/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:30:46 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/08 16:44:38 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Token	*input_to_lex(char *input)
{
	int		i;
	t_Token	*tokens;

	i = wordcount(input, ' ');
	while (i--)
	{
		*tokens = get_next_token(input);
	}
}

char	*input(char *command)
{
	char	*input;

	if (isatty(STDIN))
		input = readline(command);
	return (input);
}
