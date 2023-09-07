/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:38:06 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/07 10:25:13 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	etb(int err)
{
	if (err == 0)
		return (0);
	if (err == EPERM)
		return (1);
	if (err == EINVAL)
		return (2);
	if (err == EACCES)
		return (126);
	if (err == ENOENT)
		return (127);
	if (err == EINVAL)
		return (128);
	if (err == EIO)
		return (255);
	return (err);
}

/// Checks if the given command is a custom build function
/// @param command (t_Command) Command from the parser
/// @param envp (char **) Enviourment variables given by the main function
/// @return (int) 0 if it was a custom command, 1 if not.
int	check_customs(t_Command command)
{
	if (!ft_strncmp(command.type.lexeme, "cd", 3))
		return (cd(command.arguments[0].lexeme));
	if (!ft_strncmp(command.type.lexeme, "pwd", 4))
		return (pwd(), 0);
	if (!ft_strncmp(command.type.lexeme, "echo", 5))
		return (echo(command.arguments, command.arg_count));
	if (!ft_strncmp(command.type.lexeme, "env", 4))
		return (env(), 0);
	if (!ft_strncmp(command.type.lexeme, "exit", 5))
	{
		// printf("exit\n");
		return (custom_exit(&command));
	}
	if (!ft_strncmp(command.type.lexeme, "export", 7))
		return (export(command.arguments, command.arg_count), 0);
	if (!ft_strncmp(command.type.lexeme, "unset", 6))
		return (unset(command.arguments, command.arg_count));
	return (1);
}

int	check_export(char *str)
{
	int	index;

	if (!((str[0] >= 65 && str[0] <=90) || (str[0] >=97 && str[0] <= 122)))
		return (1);
	index = 0;
	while (str[index] != 0x00 && str[index] != '=')
	{
		if (!((str[index] >= 65 && str[index] <=90) || (str[index] >=97 && str[index] <= 122))
		&& !(str[index] >= 48 && str[index] <= 57))
			return (1);
		index++;
	}
	return (0);
}
