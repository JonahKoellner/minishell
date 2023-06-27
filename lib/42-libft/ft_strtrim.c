/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:14:47 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/19 15:53:25 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

int	checkmatch(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		slen;
	int		j;

	i = 0;
	j = 0;
	slen = ft_strlen(s1);
	if (checkmatch(set, s1[i]) && i < slen)
		while (checkmatch(set, s1[++i]))
			;
	if (checkmatch(set, s1[--slen]) && i < slen)
		while (checkmatch(set, s1[--slen]))
			;
	if (i > slen)
		return (ft_strdup(""));
	newstr = (char *)ft_calloc(slen - i + 2, 1);
	if (!newstr)
		return (0);
	while (i <= slen && s1[i])
	{
		newstr[j++] = s1[i++];
	}
	return (newstr);
}
