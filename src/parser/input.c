/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 09:07:13 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/07 17:46:07 by jkollner         ###   ########.fr       */
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
	 printf("tkn c %i \n", i);
	if (i < 0)
		return (bad_quote(input));
	else if (i == 0)
		return (empty_input(input));
	tokens = ft_calloc(i + 1, sizeof(t_Token));
	tokens[i].type = TOKEN_END;
	if (!tokens)
		return ((t_Command){.err = -2});
	while (i-- >= 0)
	{
		tokens[j++] = get_next_token(input);
		if (tokens[j - 1].type == TOKEN_END || tokens[j - 1].type == ERR)
			break ;
	}
	get_next_token(0);
	add_history(input);
	if (tokens[j - 1].type == ERR)
		return (free(input), free_tokens(tokens), (t_Command){.err = -3});
	return (free(input), parser(tokens));
}

char	*input(void)
{
	char	*input;
	char	*prompt;

	input = NULL;
	prompt = new_line();
	if (isatty(STDIN))
		input = readline(prompt);
	else
	{
		char *line = get_next_line(fileno(stdin));
		if (line != NULL)
			input = ft_strtrim(line, "\n");
		free(line);
	}
	free(prompt);
	if (!input)
	{
		custom_exit(NULL);
	}
	return (input);
}
