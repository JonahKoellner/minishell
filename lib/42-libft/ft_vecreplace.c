/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/30 11:12:21 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Finds and replaces the value in the given vector.
/// @param var
/// @param vector
/// @return
int	ft_vecreplace(char *var, char **vector)
{
	int	vec_len;
	int	equal_pos;
	int	index;

	vec_len = ft_veclen(vector);
	equal_pos = 0;
	index = 0;
	while (var[equal_pos] != '=' && var[equal_pos])
		equal_pos++;
	while (index < vec_len)
	{
		if (vector[index] != NULL)
		{
			if (ft_memcmp(vector[index], var, equal_pos) == 0)
			{
				free(vector[index]);
				vector[index] = ft_strdup(var);
				return (1);
			}
		}
		index++;
	}
	return (0);
}
