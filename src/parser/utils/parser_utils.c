/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:19:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/21 19:16:46 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_unquotable(char c)
{
	if (c == '|' || c == '&' || c ==';' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '$' || c == '`' || c == '\\'
		|| c == '"' || c == '\'' || c == ' ' || c == '\n' || c == '\t')
		return (0);
	else
		return (1);
}

int	tokencount(const char *s, char c)
{
	int		i;
	int		wrd;

	wrd = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && wrd == 0)
		{
			wrd = 1;
			i++;
		}
		if (*s == c)
			wrd = 0;
		s++;
	}
	return (i);
}
