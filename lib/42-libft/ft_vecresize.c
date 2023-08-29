/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/29 12:47:53 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vecresize(char **old_vec, size_t size)
{
	char	**new_vec;
	int		index;
	int		smaller_size;

	new_vec = ft_calloc(size + 1, sizeof(char *));
	if (new_vec == NULL)
		return (NULL);
	index = 0;
	smaller_size = ft_veclen(old_vec);
	if (smaller_size > (int)size)
		smaller_size = size;
	while (index < smaller_size)
	{
		new_vec[index] = ft_strdup(old_vec[index]);
		index++;
	}
	ft_vecfree(old_vec);
	return (new_vec);
}
