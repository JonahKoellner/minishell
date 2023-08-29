/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/29 13:12:09 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vecdelete(char *var, char **vector)
{
	char	**new_vec;
	int		vec_len;
	int		var_len;
	int		index;
	int		new_i;

	vec_len = ft_veclen(vector);
	var_len = ft_strlen(var);
	index = 0;
	new_i = 0;
	new_vec = ft_calloc(vec_len, sizeof(char *));
	while (index < vec_len)
	{
		if (vector[index] != NULL)
		{
			if (ft_memcmp(vector[index], var, var_len) == NULL)
				index++;
		}
		new_vec[new_i++] = ft_strdup(vector[index++]);
	}
	if (new_i == index)
		return (ft_vecfree(new_vec), vector);
	new_vec[new_i] = NULL;
	return (ft_vecfree(vector), new_vec);
}
