/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/08/21 13:09:32 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	free_tokens(t_Token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != TOKEN_END && tokens[i].type != ERR)
	{
		if (tokens[i].lexeme)
			free(tokens[i].lexeme);
		i++;
	}
	free(tokens);
}

t_Command	input_to_lex(char *input, char **env)
{
	int		i;
	int		j;
	t_Token	*tokens;

	(void)env;
	j = 0;
	i = tokencount(input);
	if (i < 0)
		return (bad_quote(input));
	else if (i == 0)
		return (empty_input(input));
	tokens = ft_calloc(i + 1, sizeof(t_Token));
	tokens[i].type = TOKEN_END;
	if (!tokens)
		return ((t_Command){.err = -2});
	while (i--)
	{
		tokens[j++] = get_next_token(input);
		if (tokens[j - 1].type == TOKEN_END || tokens[j - 1].type == ERR)
			break ;
	}
	get_next_token(0);
	add_history(input);
	free(input);
	if (tokens[j - 1].type == ERR)
		return (free_tokens(tokens), (t_Command){.err = -3});
	return (parser(tokens));
}

//char	*input(char *prompt)
char	*input(void)
{
	char	*input;

	input = NULL;
	if (isatty(STDIN))
	{
		new_line("");
		input = readline("");
				//readline(prompt)
	}
	// Put gnl fallback here for (testers)

	// free(prompt);
	return (input);
}
