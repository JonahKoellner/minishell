/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:07:01 by mreidenb          #+#    #+#             */
/*   Updated: 2022/08/22 13:01:04 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcl;

	srcl = ft_strlen(src);
	if (size)
	{
		if (size > srcl + 1)
			size = srcl +1;
		ft_memcpy (dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (srcl);
}
