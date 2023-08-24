/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:52:29 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/24 19:25:45 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		comblen;

	i = 0;
	j = 0;
	comblen = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(comblen + 1, sizeof(char));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	free(s2);
	return (newstr);
}
