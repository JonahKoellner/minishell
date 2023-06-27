/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:41:11 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/17 22:16:28 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (size > 0 && (__LONG_LONG_MAX__ / size) < count)
		return (0);
	mem = (char *) malloc(count * size);
	if (!mem)
		return (mem);
	ft_bzero (mem, count * size);
	return (mem);
}
