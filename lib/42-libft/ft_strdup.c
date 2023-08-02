/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:37:27 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/02 11:15:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	size_t	len;

	len = ft_strlen (s1);
	mem = ft_calloc (len + 1, sizeof(char));
	if (!mem)
		return (0);
	ft_memcpy (mem, s1, len + 1);
	return (mem);
}
