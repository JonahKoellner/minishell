/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:23:02 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/15 18:27:15 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	i;
	size_t	j;

	dstl = ft_strlen(dst);
	i = dstsize - dstl - 1;
	j = dstl;
	if (dstl >= dstsize)
		return (dstsize + ft_strlen(src));
	while (*src && i)
	{
		dst[j] = *src;
		j++;
		src++;
		i--;
	}
	dst[j] = 0;
	return (ft_strlen(dst) + ft_strlen(src));
}
