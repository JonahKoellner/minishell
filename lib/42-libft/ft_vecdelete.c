/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecdelete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/30 11:02:17 by jkollner         ###   ########.fr       */
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
	while (vector[index] != NULL)
	{
			if (ft_memcmp(vector[index], var, var_len) == 0
				&& (vector[index][var_len] == '=' || vector[index][var_len] == 0x00))
				index++;
			else
				new_vec[new_i++] = ft_strdup(vector[index++]);
	}
	if (new_i == index)
		return (new_vec[new_i - 1] = NULL, ft_vecfree(new_vec), vector);
	new_vec[new_i] = NULL;
	return (ft_vecfree(vector),new_vec);
}
