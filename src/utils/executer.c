/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/19 16:29:10 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_name(t_Command command, char **envp)
{
	int	child_pid;

	(void)command;
	(void)envp;
	child_pid = fork();
	if (child_pid == 0)
	{
		printf("hello from child\n");
		// child code
	}
	else
	{
		// parent code
	}
	printf("after execute in command_name\n");
	execute_path(command.arguments[0].lexeme, NULL, envp);
	return (0);
}

int	executer(t_Command command, char **envp)
{

	//printf("%d\n", command.type.type);
	command_name(command, envp);
	//if (command.type.type == TOKEN_COMMAND_NAME)
	return (0);
}
