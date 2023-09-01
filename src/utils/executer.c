/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/01 15:39:48 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_buildins(t_Command cmd, char *args[])
{
	char	*bin_ver;
	char	*usr_bin_ver;

	bin_ver = ft_strjoin("/bin/", cmd.type.lexeme);
	usr_bin_ver = ft_strjoin("/usr/bin/", cmd.type.lexeme);
	if (access(bin_ver, X_OK) == 0)
		execve(bin_ver,
			args, enviroment(NULL));
	else if (access(usr_bin_ver, X_OK) == 0)
		execve(usr_bin_ver,
			args, enviroment(NULL));
	free(bin_ver);
	free(usr_bin_ver);
	return (0);
}

/// Executes the programm
/// @param path (char *) Path to the executeable
/// @param args (char *) Array containing the arguments for the programm,
///  starting with its own name and ending with null.
/// @param env_var (char *) Enviroment Variables (Nullable)
/// @return (int) Returns value of executing the path.
/// 1 == function error,
/// -1 == execve error,
/// 0 == no error;
int	execute_path(t_Command cmd, char *args[])
{
	if (access(cmd.type.lexeme, X_OK) == 0)
		execve(cmd.type.lexeme, args, enviroment(NULL));
	else
	{
		search_buildins(cmd, args);
		if (errno == EACCES)
			printf("No execution rights\n");
		if (errno == ENOENT)
			printf("Command not found: %s\n", cmd.type.lexeme);
	}
	free_command(cmd);
	return (0);
}

/// Checks if the given command is a custom build function
/// @param command (t_Command) Command from the parser
/// @param envp (char **) Enviourment variables given by the main function
/// @return (int) 0 if it was a custom command, 1 if not.
int	check_customs(t_Command command)
{
	if (!ft_strncmp(command.type.lexeme, "cd", 3))
		return (cd(command.arguments->lexeme));
	if (!ft_strncmp(command.type.lexeme, "pwd", 4))
		return (pwd(), 0);
	if (!ft_strncmp(command.type.lexeme, "echo", 5))
		return (echo(command.arguments, command.arg_count));
	if (!ft_strncmp(command.type.lexeme, "env", 4))
		return (env(), 0);
	if (!ft_strncmp(command.type.lexeme, "exit", 5))
		return (custom_exit(NULL), 0);
	if (!ft_strncmp(command.type.lexeme, "export", 7))
		return (export(command.arguments, command.arg_count), 0);
	if (!ft_strncmp(command.type.lexeme, "unset", 6))
		return (unset(command.arguments, command.arg_count));
	return (1);
}

int	process_executer(t_Command command)
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
	execute_path(command, args);
	free(args);
	exit(errno);
}

/// Executes the custom command (giving it to the respective function)
/// or creates child Process and executes the path command in them
/// (again giving it to the functions)
/// @param command (t_Command) Command from the parser
/// @param envp (char **) Enviourment variables given by the main function
/// @return (int) 0
int	executer(t_Command command)
{
	int		child_pid;
	int		*ogs;
	int		*child_error;
	char	*error_env;

	ogs = open_redirect(command.in_fd, command.out_fd);
	child_error = ft_calloc(1, sizeof(int));
	if (check_customs(command) == 1)
	{
		child_pid = fork();
		signal(SIGINT, SIG_IGN);
		if (child_pid == 0)
			process_executer(command);
		else
		{
			waitpid(child_pid, child_error, 0);
			signal(SIGINT, sig_decide);
		}
	}
	error_env = ft_strjoin_free(ft_strdup("?="),
			ft_itoa(WEXITSTATUS(*child_error)));
	add_environ(error_env);
	free(child_error);
	close_redirect(ogs[0], ogs[1]);
	return (free(ogs), free_command(command), free(error_env), 0);
}
