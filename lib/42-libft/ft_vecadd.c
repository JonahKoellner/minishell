/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:55:17 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/30 11:13:13 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vectoradd(char	**vec, char *var)
{
	char	**new_vec;

	new_vec = ft_vecresize(vec, ft_veclen(vec) + 1);
	// ft_vecfree(vec);
	return (new_vec[ft_veclen(new_vec)] = ft_strdup(var), new_vec);
}
