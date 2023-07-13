/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/13 15:33:14 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd_back(t_sys_val *sys_val)
{
	long	distance;
	int		index;
	char	*new;

	distance = ft_strrchr(sys_val->dir, '/') - sys_val->dir;
	index = -1;
	new = ft_calloc(distance + 1, sizeof(char));
	while (++index < distance)
		new[index] = sys_val->dir[index];
	free(sys_val->dir);
	sys_val->dir = new;
	printf("\n%s\n", new);
	return (0);
}

int	cd_arg(t_sys_val *sys_val, char *arg)
{
	if (sys_val->dir)
		free(sys_val->dir);
	sys_val->dir = arg;
	return (0);
}
