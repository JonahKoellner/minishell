/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:04:02 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/18 04:00:27 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	strl;
	size_t	i;

	strl = ft_strlen(s);
	i = 0;
	if (strl == 0 && *s != 0)
		return (NULL);
	if (*s == 0 && strl != 0)
		return ((char *)s);
	if (!c)
		return ((char *)&s[strl]);
	while (i <= strl)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
