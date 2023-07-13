/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:20 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/13 15:29:58 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	new_line(t_sys_val *sys_val)
{
	printf("minishell>%s:$ ", sys_val->dir);
	return (0);
}
