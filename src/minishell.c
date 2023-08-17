/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/17 00:29:55 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../lib/42-libft/libft.h"

#include "minishell.h"

/*
int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**env;
	(void)argc;
	(void)argv;
	while (1)
	{
		input = input();
	}
	
}
*/

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
	return (1);
}
