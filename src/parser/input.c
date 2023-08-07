/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:30:46 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/07 14:13:05 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	free_tokens(t_Token *tokens)
//{

//}

int	input_to_lex(char *input)
{
	int		i;
	int		j;
	t_Token	*tokens;

	j = 0;
	i = tokencount(input);
	if (i < 0)
		return (bad_quote(input));
	else if (i == 0)
		return (empty_input(input));
	tokens = ft_calloc(i, sizeof(t_Token));
	while (i--)
	{
		tokens[j++] = get_next_token(input, (t_Token){NULL, TOKEN_END});
		if (tokens[j - 1].type == TOKEN_END || tokens[j - 1].type == ERR)
			break ;
	}
	get_next_token(0, (t_Token){NULL, TOKEN_END});
	add_history(input);
	free(input);
	if (tokens[j - 1].type == ERR)
		return (-3); //Would leak here, implement free tokens somwhere
	return (parser(tokens));
}

char	*input(char *command)
{
	char	*input;

	if (isatty(STDIN))
		input = readline(command);
	free(command);
	return (input);
}
