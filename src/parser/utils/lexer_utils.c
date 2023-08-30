/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:20:45 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/30 17:22:52 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_unquotable(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '$' || c == '`' || c == '\\'
		|| c == '"' || c == '\'')
		return (2);
	else if (ft_isspace(c) || c == '\0')
		return (1);
	else
		return (0);
}

int	tokencount(const char *s)
{
	int		i;
	int		wrd;
	char	qt;

	qt = 0;
	wrd = 0;
	i = 0;
	while (*s)
	{
		if ((*s == '\'' || *s == '\"' || (*s == '>' || *s == '<' || *s == '|'))
			&& qt == 0)
		{
			qt = *s++;
			i++;
		}
		if (!ft_isspace(*s) && wrd == 0 && (qt == 0 || qt == '>'
				|| qt == '<' || qt == '|'))
			wrd = ++i;
		if (ft_isspace(*s))
			wrd = 0;
		if (*s == qt || ((qt == '>' || qt == '<' || qt == '|') && *s != qt))
			qt = 0;
		s++;
	}
	return (i * ((qt - 1) * -1));
}

t_Token	lex_dollar(char *input, int *i)
{
	int		j;
	t_Token	token;

	j = 0;
	token.type = TOKEN_WORD;
	if (is_unquotable(input[*i + 1]) == 1)
		token.lexeme = ft_strdup("$");
	else
	{
		j = *i;
		*i += 1;
		token.type = TOKEN_VARIABLE;
		while (is_unquotable(input[*i]) == 0 || is_unquotable(input[*i]) == 2)
		{
			if (is_unquotable(input[*i]) == 2)
			{
				unexpected_token((t_Token){ERR, ft_substr(input, *i, 1)});
				token.type = ERR;
				break ;
			}
			*i += 1;
		}
		token.lexeme = fillstr(input, j, *i);
	}
	return (token);
}
