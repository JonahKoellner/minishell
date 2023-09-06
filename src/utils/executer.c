/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:04:52 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 13:11:48 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_buildins(t_Command cmd, char *args[])
{
	char	*path;
	char	**split_path;
	char	*cmd_name;
	int		index;

	path = get_environ_item("PATH");
	if (path == NULL)
		return (printf("No path ?>..>\n"), 1);
	split_path = ft_split(path, ':');
	index = -1;
	while (split_path[++index] != NULL)
		split_path[index] = ft_strjoin_free(split_path[index], ft_strdup("/"));
	index = 0;
	while (split_path[index] != NULL)
	{
		cmd_name = ft_strjoin(split_path[index++], cmd.type.lexeme);
		if (access(cmd_name, X_OK) == 0)
			return (execve(cmd_name, args, enviroment(NULL)),
				free(cmd_name), ft_vecfree(split_path) ,0);
		free(cmd_name);
	}
	ft_vecfree(split_path);
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
	//free_command(cmd);
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
	{
		free_command(command);
		return (custom_exit(NULL, command.arguments), 0);
	}
	if (!ft_strncmp(command.type.lexeme, "export", 7))
		return (export(command.arguments, command.arg_count), 0);
	if (!ft_strncmp(command.type.lexeme, "unset", 6))
		return (unset(command.arguments, command.arg_count));
	return (1);
}

int	process_executer(t_Command command, int *pip_og)
{
	char	**args;
	int		index;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (command.arg_count == 0)
		args = ft_calloc(3, sizeof(char *));
	else
		args = ft_calloc(command.arg_count + 2, sizeof(char *));
	if (args == NULL)
		return (printf("ft_calloc error !\n"), 1);
	args[0] = command.type.lexeme;
	index = -1;
	while (++index <= command.arg_count)
		args[index + 1] = command.arguments[index].lexeme;
	args[index] = NULL;
	execute_path(command, args);
	if (!command.next && command.arg_i == -13)
		close_redirect(pip_og, command, -1);
	else
		close_redirect(pip_og, command, 0);
	if (!command.next && command.arg_i != -13)
		free(pip_og);
	free_command(command);
	free(args);
	exit(errno);
}

/// Executes the custom command (giving it to the respective function)
/// or creates child Process and executes the path command in them
/// (again giving it to the functions)
/// @param command (t_Command) Command from the parser
/// @return (int) 0
int	executer(t_Command command, int *pip)
{
	int		child_pid;
	int		*pip_og;
	int		child_error;
	char	*error_env;

	pip_og = pip;
	if (!pip)
		pip_og = open_redirect(command.in_fd, command.out_fd, pip);
	if (check_customs(command) == 1)
	{
		child_pid = fork();
		signal(SIGINT, SIG_IGN);
		if (child_pid == 0)
			process_executer(command, pip_og);
		waitpid(child_pid, &child_error, 0);
		signal(SIGINT, sig_decide);
		error_env = ft_strjoin_free(ft_strdup("?="),
			ft_itoa(WEXITSTATUS(child_error)));
	}
	else
		error_env = ft_strjoin_free(ft_strdup("?="), ft_itoa(errno));
	if (!pip)
		close_redirect(pip_og, command, -1);
	else
		pip_og = NULL;
	return (free(pip_og), add_environ(error_env), 0);
}
