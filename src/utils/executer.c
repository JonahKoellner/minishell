/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/25 13:05:53 by jkollner         ###   ########.fr       */
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
int	execute_path(t_Command cmd, char **env_var, char *args[])
{
	if (!cmd.type.lexeme)
		return (1);
	if (access(cmd.type.lexeme, X_OK) == 0)
		execve(cmd.type.lexeme, NULL, env_var);
	else
	{
		if (errno == EACCES)
			return (printf("No execution rights\n"), 1);
		if (access(ft_strjoin("/bin/", cmd.type.lexeme), X_OK) == 0)
			execve(ft_strjoin("/bin/", cmd.type.lexeme),
				args, env_var);
		else if (access(ft_strjoin("/usr/bin/", cmd.type.lexeme), X_OK) == 0)
			execve(ft_strjoin("/usr/bin/", cmd.type.lexeme),
				args, env_var);
		else
		{
			if (errno == EACCES)
				return (printf("No execution rights\n"), 1);
			if (errno == ENOENT)
				return (printf("Command not found: %s\n",
						cmd.type.lexeme), 1);
		}
	}
	return (0);
}

/**
 * Checks if the given command is a custom build function
 *
 * @param command (t_Command) Command from the parser
 * @param envp (char **) Enviourment variables given by the main function
 *
 * @return (int) 0 if it was a custom command, 1 if not.
 *
*/
int	check_customs(t_Command command, char **envp)
{
	(void)envp;
	if (!ft_strncmp(command.type.lexeme, "cd", 3))
		return (cd(command.arguments->lexeme), 0);
	if (!ft_strncmp(command.type.lexeme, "pwd", 4))
		return (pwd(), 0);
	if (!ft_strncmp(command.type.lexeme, "echo", 5))
		return (echo(command.arguments[0].lexeme, 0), 0);
	if (!ft_strncmp(command.type.lexeme, "env", 4))
		return (env(), 0);
	if (!ft_strncmp(command.type.lexeme, "exit", 5))
		return (custom_exit(NULL), 0);
	if (!ft_strncmp(command.type.lexeme, "export", 7))
		return (export(envp), 0);
	return (1);
}

/**
 * Executes the custom command (giving it to the respective function)
 * or creates child Process and executes the path command in them
 * (again giving it to the functions)
 * @param command (t_Command) Command from the parser
 * @param envp (char **) Enviourment variables given by the main function
 *
 * @return (int) 0
 *
*/
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
			if (command.arg_count == 0)
				args[1] = NULL;
			args[2] = NULL;
			printf("%p\t%p\n", args[0], args[1]);
			execute_path(command, envp, args);
			perror("execve");
			free(args);
			exit(1);
		}else
			waitpid(child_pid, NULL, 0);
	}
	return (0);
}
