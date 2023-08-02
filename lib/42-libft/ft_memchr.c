/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:27:24 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/01 20:08:11 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	nc;
	unsigned char	*str;

	nc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == nc)
			return ((void *)str);
		str++;
	}
	return (0);
}
