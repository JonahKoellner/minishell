/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:01:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/29 23:12:44 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	in_out(t_Token type, t_Token where, t_Command cmd, int *i)
{
	if (type.type == TOKEN_GREAT)
		cmd.out_fd = open(where.lexeme, O_WRONLY | O_CREAT, 0644);
	else if (type.type == TOKEN_GREAT_GREAT)
		cmd.out_fd = open(where.lexeme, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else if (type.type == TOKEN_LESS)
		cmd.in_fd = open(where.lexeme, O_RDONLY);
	else if (type.type == TOKEN_LESS_LESS)
		cmd.in_fd = make_heredoc(ft_strdup(where.lexeme));
	free(where.lexeme);
	*i += 1;
	return (cmd);
}

t_Command	check_parsed(t_Command cmds, t_Token *tokens)
{
	// t_Command	cmd;
	int			i;
	int			n;

	i = 0;
	n = cmd_count(tokens);
	free(tokens);
	// cmd = cmds;
	while (i < n)
	{
		if (cmds.type.type == ERR)
			return (unclosed_pipe());
		if (cmds.arg_i != cmds.arg_count)
			return ((t_Command){.err = -7});
		if (cmds.in_fd < 0 || cmds.out_fd < 0)
			return (free_command(cmds), open_error(cmds.in_fd, cmds.out_fd));
		i++;
	}
	return (cmds);
}

// t_Command	check_parsed(t_Command cmds, t_Token *tokens)
// {
// 	t_Command	cmd;
// 	int			i;
// 	int			n;

// 	i = 0;
// 	n = cmd_count(tokens);
// 	free(tokens);
// 	cmd = cmds;
// 	while (i < n)
// 	{
// 		if (cmd.type.type == ERR)
// 			return (free_command(cmds), unclosed_pipe());
// 		if (cmd.arg_i != cmd.arg_count)
// 			return (free_command(cmds), (t_Command){.err = -7});
// 		if (cmd.in_fd < 0 || cmd.out_fd < 0)
// 			return (free_command(cmds), open_error(cmd.in_fd, cmd.out_fd));
// 		i++;
// 		if (cmds.next)
// 			cmd = *(t_Command *)cmds.next;
// 	}
// 	return (cmds);
// }

t_Command	*parser_next(t_Token *tokens)
{
	int			i;
	t_Command	*cmd;

	i = 0;
	cmd = ft_calloc(1, sizeof(t_Command));
	*cmd = std_command(tokens);
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_PIPE)
			return (cmd->next = parser_next(&tokens[++i]), cmd);
		if (!is_allowed_token(tokens[i]) && is_allowed_token(tokens[i + 1]))
			*cmd = in_out(tokens[i], tokens[i + 1], *cmd, &i);
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
	t_Command	cmds;

	i = 0;
	cmds = std_command(tokens);
	while (tokens[i].type != TOKEN_END && cmds.err == 0)
	{
		if (tokens[i].type == TOKEN_PIPE)
		{
			cmds.next = parser_next(&tokens[++i]);
			return (check_parsed(cmds, tokens));
		}
		if (tokens[i].type == TOKEN_STRING || tokens[i].type == TOKEN_VARIABLE)
			tokens[i].lexeme = var_expander(tokens[i].lexeme);
		if (!is_allowed_token(tokens[i]) && is_allowed_token(tokens[i + 1]))
			cmds = in_out(tokens[i], tokens[i + 1], cmds, &i);
		else if (!is_allowed_token(tokens[i]))
			return (unexpected_token(tokens[i + 1]));
		else if (is_allowed_token(tokens[i]) && cmds.type.lexeme == NULL)
			cmds.type = tokens[i];
		else if (is_allowed_token(tokens[i]))
			cmds.arguments[cmds.arg_i++] = tokens[i];
		i++;
	}
	return (check_parsed(cmds, tokens));
}
