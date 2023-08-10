/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:01:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/10 21:54:38 by mreidenb         ###   ########.fr       */
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
}

int	check_parsed(t_Command *cmds, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (cmds[i].type.type == ERR)
			return (unclosed_pipe());
		if (cmds[i].arg_i != cmds[i].arg_count - 1)
			return (-7);
		i++;
	}
}

int	parser(t_Token *tokens)
{
	int			i;
	int			j;
	int			n;
	t_Command	*cmds;

	i = 0;
	j = -1;
	n = cmd_count(tokens);
	cmds = ft_calloc(n + 1, sizeof(t_Command));
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_PIPE || j < 0)
			cmds[++j] = std_command(cmds[j], &tokens[i++]);
		if (!is_allowed_token(tokens[i]) && is_allowed_token(tokens[i + 1]))
			cmds[j] = parse_redirect(tokens[i], tokens[i + 1], cmds[j]);
		else
			return (unexpected_token(tokens[i + 1]));
		if (is_allowed_token(tokens[i]) && !cmds[j].type.lexeme)
			cmds[j].type = tokens[i];
		else if (is_allowed_token(tokens[i]))
			cmds[j].arguments[cmds[j].arg_i++] = tokens[i];
	}
	return (free_unused_tokens(tokens), free(tokens), check_parsed(cmds, n));
}
