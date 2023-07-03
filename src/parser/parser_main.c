/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:01:12 by mreidenb          #+#    #+#             */
/*   Updated: 2023/06/27 16:39:52 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*fillstr(const char *str, int z, int fin)
{
	char	*fill;
	int		i;

	i = 0;
	if (!*str)
		return (NULL);
	fill = (char *)malloc((fin - z + 1) * sizeof(char));
	if (!fill)
		return (NULL);
	while (z < fin)
		fill[i++] = str[z++];
	fill[i] = 0;
	return (fill);
}

t_Token	redirect_decide(t_Token token, int *i)
{
	if (token.lexeme[0] == '>' && token.lexeme[1] != '>')
		token.type = TOKEN_GREAT;
	else if (token.lexeme[0] == '>' && token.lexeme[1] == '>')
		token.type = TOKEN_GREAT_GREAT;
	else if (token.lexeme[0] == '<' && token.lexeme[1] != '<')
		token.type = TOKEN_LESS;
	else if (token.lexeme[0] == '<' && token.lexeme[1] == '<')
		token.type = TOKEN_LESS_LESS;
	else if (token.lexeme[0] == '|' && token.lexeme[1] != '|')
		token.type = TOKEN_PIPE;
	if (token.type == TOKEN_GREAT_GREAT || TOKEN_LESS_LESS)
		*i++;
	free(token.lexeme);
	return (token);
}

//gets the next token, after complete command call with command = NULL
t_Token	get_next_token(char *command)
{
	t_Token		token;
	static int	i = 0;
	int			j;

	if (!command)
		i = 0;
	while (command[i] == ' ', command[i] == '\t', command[i] == '\n')
		i++;
	if (ft_isalnum(command[i]))
	{
		j = i;
		while (ft_isalnum(command[i]))
			i++;
		token.lexeme = fillstr(command, j, i);
		token.type = TOKEN_WORD;
		return (token);
	}
	if (command[i] == '>' || command[i] != '<' || command[i] != '|')
	{
		token.type = TOKEN_REDIRECT;
		token.lexeme = fillstr(command, i, i + 1);
		i++;
		return (redirect_decide(token, &i));
	}
	return (token);
}
