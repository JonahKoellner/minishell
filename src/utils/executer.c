/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/29 11:50:31 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Executes the programm
/// @param path (char *) Path to the executeable
/// @param args (char *) Array containing the arguments for the programm,
///  starting with its own name and ending with null.
/// @param env_var (char *) Enviroment Variables (Nullable)
/// @return (int) Returns value of executing the path.
/// 1 == function error,
/// -1 == execve error,
/// 0 == no error;
int	execute_path(t_Command cmd, char **env_var, char *args[])
{
	if (!cmd.type.lexeme)
		return (1);
	if (access(cmd.type.lexeme, X_OK) == 0)
		execve(cmd.type.lexeme, args, env_var);
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

/// Checks if the given command is a custom build function
/// @param command (t_Command) Command from the parser
/// @param envp (char **) Enviourment variables given by the main function
/// @return (int) 0 if it was a custom command, 1 if not.
int	check_customs(t_Command command, char **envp)
{
	(void)envp;
	if (!ft_strncmp(command.type.lexeme, "cd", 3))
		return (cd(command.arguments->lexeme, envp), 0);
	if (!ft_strncmp(command.type.lexeme, "pwd", 4))
		return (pwd(), 0);
	if (!ft_strncmp(command.type.lexeme, "echo", 5))
		return (echo(command.arguments, command.arg_count));
	if (!ft_strncmp(command.type.lexeme, "env", 4))
		return (env(), 0);
	if (!ft_strncmp(command.type.lexeme, "exit", 5))
		return (custom_exit(NULL), 0);
	if (!ft_strncmp(command.type.lexeme, "export", 7))
		return (export(command.arguments, command.arg_count, envp), 0);
	if (!ft_strncmp(command.type.lexeme, "unset", 6))
		return (unset(command.arguments[0].lexeme, envp));
	return (1);
}

int	process_executer(t_Command command, char **envp)
{
	char	**args;
	int		index;

	signal(SIGINT, SIG_DFL);
	if (command.arg_count == 0)
		args = ft_calloc(3, sizeof(char *));
	else
		args = ft_calloc(command.arg_count + 2, sizeof(char *));
	if (args == NULL)
		return (printf("ft_calloc error !\n"), 1);
	args[0] = command.type.lexeme;
	index = 0;
	while (index <= command.arg_count)
	{
		args[index + 1] = command.arguments[index].lexeme;
		index++;
	}
	args[index] = NULL;
	execute_path(command, envp, args);
	// perror("execve");
	free(args);
	exit(1);
}

/// Executes the custom command (giving it to the respective function)
/// or creates child Process and executes the path command in them
/// (again giving it to the functions)
/// @param command (t_Command) Command from the parser
/// @param envp (char **) Enviourment variables given by the main function
/// @return (int) 0
int	executer(t_Command command, char **envp)
{
	int		child_pid;

	if (check_customs(command, envp) == 1)
	{
		child_pid = fork();
		signal(SIGINT, SIG_IGN);
		if (child_pid == 0)
		{
			process_executer(command, envp);
		}
		else
		{
			waitpid(child_pid, NULL, 0);
			signal(SIGINT, sig_decide);
		}
	}
	return (0);
}
