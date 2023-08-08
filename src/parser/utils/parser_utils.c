/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:19:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/08 02:49:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_unquotable(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '$' || c == '`' || c == '\\'
		|| c == '"' || c == '\'')
		return (2);
	else if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

int	tokencount(const char *s)
{
	int		i;
	int		wrd;
	char	qte;

	qte = 0;
	wrd = 0;
	i = 0;
	while (*s)
	{
		if ((*s == '\'' || *s == '"') && qte == 0)
		{
			qte = *s;
			i++;
		}
		if ((*s == ' ' || *s == '\n' || *s == '\t') && wrd == 0 && qte == 0)
			wrd = ++i;
		if (*s == ' ' || *s == '\n' || *s == '\t')
			wrd = 0;
		s++;
		if (*s == qte)
			qte = NULL;
	}
	return (i * ((qte - 1) * -1));
}

t_Token	lex_dollar(char *input, int *i)
{
	int		j;
	t_Token	token;

	i = 0;
	token.type = TOKEN_WORD;
	if (is_unquotable(input[*i + 1]) == 1)
		token.lexeme = ft_strdup("$");
	else
	{
		j = *i;
		token.type = TOKEN_VARIABLE;
		while (is_unquotable(input[*i]) == 0 || is_unquotable(input[*i]) == 2)
		{
			if (is_unquotable(input[*i] == 2))
			{
				unexpected_token((t_Token){ERR, ft_substr(input, *i, 1)});
				token.type = ERR;
				break ;
			}
			*i++;
		}
		token.lexeme = fillstr(input, j, i);
	}
	return (token);
}

int	is_allowed_token(t_Token token)
{
	if (token.type == TOKEN_WORD
		|| token.type == TOKEN_VARIABLE
		|| token.type == TOKEN_LITERAL_CHARS
		|| token.type == TOKEN_LITERAL_STRING
		|| token.type == TOKEN_COMMAND_NAME)
		return (1);
	else
		return (0);
}
