/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/01 19:42:32 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/42-libft/libft.h"

#include "minishell.h"


int	main(void)
{
	//char	*command;
	char	*start_dir;

	t_sys_val *sys = malloc(sizeof(t_sys_val));
	start_dir = malloc(sizeof(char) * 16);
	ft_strlcpy(start_dir, "Dev/42/minishell", 16);
	cd_arg(sys, start_dir);
	new_line(sys);
	cd_back(sys);
	new_line(sys);
	//while (1)
	//{
	//	new_line();
	//	//add_history(command);
	//	//printf("exec %s\n", command);
	//	//if (strncmp(command, "exit", 4) == 0)
	//		//break ;
	//}
	return (1);
}
