/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/23 11:13:47 by jkollner         ###   ########.fr       */
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

int	command_name(t_Command command, char **envp)
{
	int		child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execute_path(command, envp,
			(char *[3]){command.type.lexeme,
			command.arguments[0].lexeme, NULL});
		_exit(0);
	}
	else
	{
		waitpid(child_pid, NULL, 0);
	}
	return (0);
}

int	executer(t_Command command, char **envp)
{
	//printf("%d\n", command.type.type);
	// if (command.type.type == TOKEN_COMMAND_NAME)
	// {
		if (!ft_strncmp(command.type.lexeme, "cd", 3))
			cd(command.arguments->lexeme);
		else if (!ft_strncmp(command.type.lexeme, "pwd",
				4))
			pwd();
		// if (!ft_strncmp(command.type.lexeme, "export",
		// 		ft_strlen(command.type.lexeme)))
		// 	export();
		// if (!ft_strncmp(command.type.lexeme, "unset",
		// 		ft_strlen(command.type.lexeme)))
		// 	unset();
		else if (!ft_strncmp(command.type.lexeme, "env",
				4))
			env();
		else if (!ft_strncmp(command.type.lexeme, "exit",
				5))
			custom_exit(NULL);
		else if (!ft_strncmp(command.type.lexeme, "history",
				5))
			print_history();
		else
			command_name(command, envp);
	// }
	return (0);
}
