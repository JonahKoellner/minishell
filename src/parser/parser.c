/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:01:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/08 02:19:52 by mreidenb         ###   ########.fr       */
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
}

int	parser(t_Token *tokens)
{
	int			i;
	t_Command	command;

	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_GREAT || tokens[i].type == TOKEN_LESS
			|| tokens[i].type == TOKEN_GREAT_GREAT
			|| tokens[i].type == TOKEN_LESS_LESS)
		{
			if (is_allowed_token(tokens[i + 1]))
				command = parse_redirect(tokens[i], tokens[i + 1], command);
			else
				return (unexpected_token(tokens[i + 1]));
		}
	}
}
