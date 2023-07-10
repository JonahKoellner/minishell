/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/08 10:06:34 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd_back(t_sys_val *sys_val)
{
	char	**new_dir_split;

	new_dir_split = ft_split(sys_val->dir, '/');
}

int	cd_arg(t_sys_val *sys_val, char *arg)
{
	sys_val->dir = arg;
}
