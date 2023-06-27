/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:36:29 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/18 05:38:00 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;

	i = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	substr = (char *)ft_calloc(len + 1, 1);
	if (ft_strlen(s) < start)
		return (substr);
	if (!substr)
		return (0);
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	if (substr)
		substr[i] = 0;
	return (substr);
}
