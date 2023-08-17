/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:32:00 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 03:51:16 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vecdup(const char **vec)
{
	char	**ret_vec;
	int		i;

	i = 0;
	if (!vec)
		return (NULL);
	ret_vec = ft_calloc(ft_veclen(vec) + 1, sizeof(char *));
	if (!ret_vec)
		return (NULL);
	while (vec[i])
	{
		ret_vec[i] = ft_strdup(vec[i]);
		if (!ret_vec[i])
			return (ft_vecfree(ret_vec), NULL);
		i++;
	}
	ret_vec[i] = NULL;
	return (ret_vec);
}
