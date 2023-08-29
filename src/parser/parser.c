/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:01:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/28 15:11:52 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	in_out(t_Token type, t_Token where, t_Command cmd)
{
	if (type.type == TOKEN_GREAT)
		cmd.out_file = ft_strdup(where.lexeme);
	else if (type.type == TOKEN_LESS)
		cmd.in_file = ft_strdup(where.lexeme);
	else if (type.type == TOKEN_LESS_LESS)
		cmd = make_heredoc(cmd, ft_strdup(where.lexeme));
	free(where.lexeme);
	free(type.lexeme);
	return (cmd);
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
			in_out(tokens[i], tokens[i + 1], *cmd);
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
	cmds = (t_Command){{ERR, NULL}, 0, 0, NULL, 0, 0, NULL, NULL, 0, NULL};
	cmds = std_command(cmds, tokens);
	while (tokens[i].type != TOKEN_END && cmds.err == 0)
	{
		if (tokens[i].type == TOKEN_PIPE)
			return (cmds.next = parser_next(&tokens[++i]), cmds);
		if (tokens[i].type == TOKEN_STRING || tokens[i].type == TOKEN_VARIABLE)
			tokens[i].lexeme = var_expander(tokens[i].lexeme);
		if (!is_allowed_token(tokens[i]) && is_allowed_token(tokens[i + 1]))
			cmds = in_out(tokens[i], tokens[i + 1], cmds);
		else if (!is_allowed_token(tokens[i]))
			return (unexpected_token(tokens[i + 1]));
		else if (is_allowed_token(tokens[i]) && cmds.type.lexeme == NULL)
			cmds.type = tokens[i];
		else if (is_allowed_token(tokens[i]))
			cmds.arguments[cmds.arg_i++] = tokens[i];
		i++;
	}
	return (free(tokens), check_parsed(cmds, n));
}
