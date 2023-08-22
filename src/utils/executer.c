/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/22 14:02:17 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_name(t_Command command, char **envp)
{
	// int	child_pid;

	// child_pid = fork();
	// if (child_pid == 0)
	// {
		// printf("child starting command ...\n");
		execute_path(command.type.lexeme, NULL, envp);
		// child code
	// }
	// else
	// {
		// parent code
	// }
	return (0);
}

int	executer(t_Command command, char **envp)
{
	// check for custom function
	printf("test %s err %i \n", command.type.lexeme, command.err);
	// if (!ft_strncmp(command.type.lexeme, "cd", ft_strlen(command.type.lexeme)))
	// 	cd("/Users/jkollner/Dev");
	// 	// cd(command.arguments[0].lexeme);
	// if (!ft_strncmp(command.type.lexeme, "pwd", ft_strlen(command.type.lexeme)))
	// 	pwd();
	// // if (!ft_strncmp(command.type.lexeme, "export",
	// // 		ft_strlen(command.type.lexeme)))
	// // 	export();
	// // if (!ft_strncmp(command.type.lexeme, "unset",
	// // 		ft_strlen(command.type.lexeme)))
	// // 	unset();
	// if (!ft_strncmp(command.type.lexeme, "env", ft_strlen(command.type.lexeme)))
	// 	env();
	if (!ft_strncmp(command.type.lexeme, "exit",
			ft_strlen(command.type.lexeme)))
		custom_exit(NULL);

	// //printf("%d\n", command.type.type);
	// if (command.type.type == TOKEN_COMMAND_NAME)
		command_name(command, envp);
	return (0);
}
