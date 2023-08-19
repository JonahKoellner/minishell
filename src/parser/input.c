/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:30:46 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/19 15:55:13 by jonahkollne      ###   ########.fr       */
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
	tokens = ft_calloc(i, sizeof(t_Token));
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
		input = readline("very small shell > ");
				//readline(prompt)

	// Put gnl fallback here for (testers)

	// free(prompt);
	return (input);
}
