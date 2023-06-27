/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:27:24 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/13 20:50:01 by mreidenb         ###   ########.fr       */
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
