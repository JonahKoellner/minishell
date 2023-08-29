/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/29 12:16:06 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Duplicates the old vector into a new one with a new size
/// It can cut or extend the vector
/// @param old_vec
/// @param size
/// @return
char	**vec_resize(char **old_vec, size_t size)
{
	char	**new_vec;
	int		index;
	int		smaller_size;

	new_vec = ft_calloc(size, sizeof(char *));
	if (new_vec == NULL)
		return (NULL);
	index = 0;
	smaller_size = ft_veclen((const char **)old_vec);
	if (smaller_size > (int)size)
		smaller_size = size;
	while (index < smaller_size)
	{
		new_vec[index] = old_vec[index];
		index++;
	}
	free(old_vec);
	return (new_vec);
}

/// @brief Adds a value to the vector. Works by checking first if there is an
/// empty spot, so only reallocation if neccessary, and inserts it or resizes
/// and appends the value
///f @param vec
/// @param var
/// @return
char	**vector_add(char	**vec, char *var)
{
	int		vec_len;
	char	**new_vec;

	vec_len = ft_veclen((const char **)vec) - 1;
	while (vec_len >= 0)
	{
		if (vec[vec_len] == NULL)
			return (vec[vec_len] = var, vec);
	}
	new_vec = vec_resize(vec, ft_veclen((const char **)vec) + 1);
	ft_vecfree(vec);
	return (new_vec[ft_veclen((const char **)new_vec) - 1] = var, new_vec);
}

/// @brief Finds and replaces the value in the given vector;
/// @param var
/// @param vector
/// @return
int	vec_replace(char *var, char	**vector)
{
	int	vec_len;
	int	var_len;

	vec_len = ft_veclen((const char **)vector) - 1;
	var_len = ft_strlen(var);
	while (vec_len >= 0)
	{
		// NULL check cause memcmp is not protected
		if (vector[vec_len] != NULL)
		{
		// check for variable name;
			if (ft_memcmp(vector[vec_len], var, var_len) == '=')
			{
				// replace
				free(vector[vec_len]);
				vector[vec_len] = ft_strdup(var);
				return (1);
			}
		}
		vec_len--;
	}
	return (0);
}

/// @brief Finds and deletes a given value;
/// @param var
/// @param vector
/// @return
int	vec_delete(char	*var, char	**vector)
{
	int	vec_len;
	int	var_len;

	vec_len = ft_veclen((const char **)vector) - 1;
	var_len = ft_strlen(var);
	while (vec_len >= 0)
	{
		// NULL check cause memcmp is not protected
		if (vector[vec_len] != NULL)
		{
		// check for variable name;
			if (ft_memcmp(vector[vec_len], var, var_len) == '=')
			{
				// replace
				free(vector[vec_len]);
				vector[vec_len] = NULL;
				return (1);
			}
		}
		vec_len--;
	}
	return (0);
}
