/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:37:27 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/19 17:02:51 by mreidenb         ###   ########.fr       */
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
	mem = (char *) malloc (len);
	if (!mem)
		return (0);
	ft_memcpy (mem, s1, len + 1);
	return (mem);
}
