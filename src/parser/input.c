/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:30:46 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/21 19:14:33 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Token	*input_to_lex(char *input)
{
	int		i;
	int		j;
	t_Token	*tokens;

	j = 0;
	i = wordcount(input, ' ');
	tokens = ft_calloc(i, sizeof(t_Token));
	while (i--)
	{
		tokens[j++] = get_next_token(input);
		if (tokens[j - 1].type == TOKEN_END)
			break;
	}
	get_next_token(0);
	free(input);
}

char	*input(char *command)
{
	char	*input;

	if (isatty(STDIN))
		input = readline(command);
	free(command);
	return (input);
}
