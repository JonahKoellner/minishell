/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:30:46 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/11 15:18:28 by mreidenb         ###   ########.fr       */
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
	tokens = malloc(sizeof(t_Token) * i);
	while (i--)
	{
		tokens[j++] = get_next_token(input);
	}
}

char	*input(char *command)
{
	char	*input;

	if (isatty(STDIN))
		input = readline(command);
	return (input);
}
