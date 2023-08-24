/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/24 15:39:19 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes the programm
 *
 * @param path (char *) Path to the executeable
 * @param args (char *) Array containing the arguments for the programm,
 *  starting with its own name and ending with null.
 * @param env_var (char *) Enviroment Variables (Nullable)
 *
 * @return (int) Returns value of executing the path.
 * 1 == function error,
 * -1 == execve error,
 * 0 == no error;
 *
*/
int	execute_path(t_Command command, char **env_var, char *args[])
{
	if (!command.type.lexeme)
		return (1);
	// printf("executer with: %s\n", command.type.lexeme);
	if (access(command.type.lexeme, X_OK) == 0)
		execve(command.type.lexeme, NULL, env_var);
	else
	{
		if (errno == EACCES)
			return (printf("No execution rights\n"), 1);
		if (access(ft_strjoin("/bin/", command.type.lexeme), X_OK) == 0)
			execve(ft_strjoin("/bin/", command.type.lexeme),
				args, env_var);
		else
		{
			if (errno == EACCES)
				return (printf("No execution rights\n"), 1);
			if (errno == ENOENT)
				return (printf("Command not found: %s\n",
						command.type.lexeme), 1);
		}
	}
	return (0);
}

int	check_customs(t_Command command, char **envp)
{
	(void)envp;
	if (!ft_strncmp(command.type.lexeme, "cd", 3))
		return (cd(command.arguments->lexeme), 0);
	if (!ft_strncmp(command.type.lexeme, "pwd", 4))
		return(pwd(), 0);
	if (!ft_strncmp(command.type.lexeme, "echo", 5))
		return (echo(command.arguments[0].lexeme, 0), 0);
	if (!ft_strncmp(command.type.lexeme, "env", 4))
		return (env(), 0);
	if (!ft_strncmp(command.type.lexeme, "exit", 5))
		return (custom_exit(NULL), 0);
	//if (!ft_strncmp(command.type.lexeme, "history", 5))
	//	return (print_history(), 0);
	return (1);
}

int	executer(t_Command command, char **envp)
{
	int		child_pid;
	char	**args;


	if (check_customs(command, envp) == 1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			args = ft_calloc(3, sizeof(char *));
			if (args == NULL)
				printf("fuck calloc\n");
			args[0] = command.type.lexeme;
			args[1] = command.arguments[0].lexeme;
			args[2] = NULL;
			execute_path(command, envp, args);
			perror("execve");
			exit(1);
		}else
			waitpid(child_pid, NULL, 0);
	}
	// child_pid = fork();
	// if (child_pid == 0)
	// {
	// 	// Child Code
	// 	if (check_customs(command, envp) == 1)
	// 	{
	// 		execute_path(command, envp, (char *[3]){command.type.lexeme,
	// 			command.arguments[0].lexeme, NULL});
	// 	}
	// 	exit(0); // Exit child Process
	// }
	// else
	// 	waitpid(child_pid, NULL, 0);


	// printf("%d\n", command.type.type);
	// // if (command.type.type == TOKEN_COMMAND_NAME)
	// // {

	// 	else
	// 		command_name(command, envp);
	// // }
	return (0);
}
