/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 03:32:25 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 03:36:35 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecfree(char **vec)
{
	size_t	i;

	i = 0;
	if (vec == NULL)
		return ;
	while (vec[i] != NULL)
		free(vec[i++]);
	free(vec);
}
