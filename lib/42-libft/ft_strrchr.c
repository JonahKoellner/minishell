/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:56:31 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/18 04:50:30 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int	strl;

	strl = ft_strlen(s) - 1;
	if (!(char)c)
		return ((char *)&s[ft_strlen(s)]);
	if (!s)
		return (NULL);
	while (strl >= 0 && s[strl])
	{
		if (s[strl] == (unsigned char)c)
			return ((char *)&s[strl]);
		strl--;
	}
	return (NULL);
}
