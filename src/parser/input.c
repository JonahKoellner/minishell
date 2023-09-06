/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:07:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 08:54:24 by jkollner         ###   ########.fr       */
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

t_Command	input_to_lex(char *input)
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

char	*input(void)
{
	char	*input;
	char	*prompt;

	input = NULL;
	prompt = new_line();
	if (isatty(STDIN))
		input = readline(prompt);
	// Put gnl fallback here for (testers)
	free(prompt);
	if (!input)
		custom_exit(NULL, 0);
	return (input);
}
