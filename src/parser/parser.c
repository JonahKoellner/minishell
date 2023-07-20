/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:01:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/20 17:40:30 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_Token *tokens)
{
	int			i;
	t_Command	command;

	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type == TOKEN_GREAT)
			command.out_file = ft_strdup(tokens[i + 1].lexeme);
		if (tokens[i].type == TOKEN_LESS)
			command.in_file = ft_strdup(tokens[i + 1].lexeme);
	}
}
