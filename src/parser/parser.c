/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:01:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/23 09:56:57 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	parse_redirect(t_Token type, t_Token where, t_Command command_pre)
{
	t_Command	command;

	command = command_pre;
	if (type.type == TOKEN_GREAT)
		command.out_file = ft_strdup(where.lexeme);
	if (type.type == TOKEN_LESS)
		command.in_file = ft_strdup(where.lexeme);
	free(where.lexeme);
	free(type.lexeme);
	return (command);
}

t_Command	check_parsed(t_Command cmds, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (cmds.type.type == ERR)
			return (unclosed_pipe());
		if (cmds.arg_i != cmds.arg_count)
			return ((t_Command){.err = -7});
		i++;
	}
	return (cmds);
}

t_Command	*parser_next(t_Token *tokens)
{
	int			i;
	//int			n;
	t_Command	*cmd;

	i = 0;
	//n = cmd_count(tokens);
	cmd = ft_calloc(1, sizeof(t_Command));
	*cmd = std_command(*cmd, tokens);
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_PIPE)
			return (cmd->next = parser_next(&tokens[++i]), cmd);
		if (!is_allowed_token(tokens[i]) && is_allowed_token(tokens[i + 1]))
			parse_redirect(tokens[i], tokens[i + 1], *cmd);
		else if (!is_allowed_token(tokens[i]))
			return (*cmd = unexpected_token(tokens[i + 1]), cmd);
		if (is_allowed_token(tokens[i]) && cmd->type.lexeme == NULL)
			cmd->type = tokens[i];
		else if (is_allowed_token(tokens[i]))
			cmd->arguments[cmd->arg_i++] = tokens[i];
		i++;
	}
	return (cmd);
}

t_Command	parser(t_Token *tokens)
{
	int			i;
	int			n;
	t_Command	cmds;

	i = 0;
	n = cmd_count(tokens);
	// ft_printf("parser %s \n", tokens[0].lexeme);
	cmds = (t_Command){{ERR, NULL}, 0, 0, NULL, NULL, NULL, 0, NULL};
	cmds = std_command(cmds, tokens);
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_PIPE)
		{
			return (cmds.next = parser_next(&tokens[++i]), cmds);
		}
		if (!is_allowed_token(tokens[i]) && is_allowed_token(tokens[i + 1]))
			cmds = parse_redirect(tokens[i], tokens[i + 1], cmds);
		else if (!is_allowed_token(tokens[i]))
			return (unexpected_token(tokens[i + 1]));
		if (is_allowed_token(tokens[i]) && cmds.type.lexeme == NULL)
			cmds.type = tokens[i];
		else if (is_allowed_token(tokens[i]))
			cmds.arguments[cmds.arg_i++] = tokens[i];
		i++;
	}
	//ft_printf("parser end %s \n", cmds.type.lexeme);
	return (free(tokens), check_parsed(cmds, n));
}
