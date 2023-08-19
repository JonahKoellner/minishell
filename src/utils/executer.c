/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/19 15:38:22 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_name(t_Command command, char **envp)
{
	int	child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		// child code
	}
	else
	{
		// parent code
	}
	execute_path();
	return (0);
}

int	executer(t_Command command, char **envp)
{
	if (command.type.type == TOKEN_COMMAND_NAME)
		command_name(command, envp);
	return (0);
}
