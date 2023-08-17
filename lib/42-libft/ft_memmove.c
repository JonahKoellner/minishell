/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:22:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 10:09:14 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*d;
	const unsigned char		*s;

	i = len - 1;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d && !s)
		return (dst);
	if (d < s)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len--)
	{
		d[i] = s[i];
		i--;
	}
	return (dst);
}
