/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:09:20 by mreidenb          #+#    #+#             */
/*   Updated: 2023/01/03 17:17:13 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	wordcount(const char *s, char c)
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

void	assign_values(int *i, int *j, size_t *z)
{
	*i = 0;
	*j = -1;
	*z = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**strarr;
	int		i;
	int		j;
	size_t	z;

	if (!s)
		return (0);
	assign_values(&i, &j, &z);
	strarr = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!strarr)
		return (0);
	strarr[wordcount(s, c)] = 0;
	while (++z <= ft_strlen(s))
	{
		if (s[z] != c && j < 0)
			j = z;
		else if ((s[z] == c || z == ft_strlen(s)) && j >= 0)
		{
			strarr[i++] = fillstr(s, j, z);
			if (!strarr[i - 1])
				return (NULL);
			j = -1;
		}
	}
	return (strarr);
}
