/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:58:19 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 17:15:25 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Build in Function Echo
/// Prints given string with or without new line
/// @param string (char *) String to be printed.
/// @param n_flag (int) New line flag (0 = no new line, 1 = new line)
/// @return Returns 0 on success, no failure catched for now.
int	echo(t_Token *arguments, int arg_count)
{
	int	index;
	int	n_flag;

	index = 0;
	n_flag = 0;
	if (!arg_count)
		return (ft_printf("\n"), 0);
	while (!ft_strncmp(arguments[index].lexeme, "-n", 3))
	{
		n_flag = 1;
		if (++index >= arg_count)
			break ;
	}
	if (index < arg_count)
	{
		while (arguments[index].lexeme)
		{
			ft_printf("%s", arguments[index++].lexeme);
			if (index != arg_count)
				ft_printf(" ");
		}
	}
	if (!n_flag)
		ft_printf("\n");
	return (0);
}

/// @brief Prints enviorment
/// @param void (void) No Parameter.
/// @return Returns 0 on success, no failure catched for now.
int	env(void)
{
	char	**envp;
	int		index;

	envp = enviroment(NULL);
	index = 0;
	while (envp[index])
	{
		if (ft_strchr(envp[index], '='))
			printf("%s\n", envp[index]);
		index++;
	}
	return (0);
}

/// @brief Prints or sets the enviroment variables for the current shell session
/// @param envp (char **) enviorment of the system;
/// given by the main function.
/// @return Returns 0 on success, no failure catched for now.
int	export(t_Token *input, int c_arg)
{
	int		index;
	char	**envp;

	if (c_arg)
	{
		index = 0;
		while (input[index].lexeme)
		{
			if (input[index].lexeme[0] != '=')
				add_environ(ft_strdup(input[index++].lexeme));
			else
				printf("bash: export: `%s': not a valid identifier\n",
					input[index++].lexeme);
		}
	}
	else
	{
		envp = enviroment(NULL);
		index = 0;
		while (envp[index])
			printf("%s\n", envp[index++]);
	}
	return (0);
}

/// @brief Unsets the given enviroment varible fromt the given eniroment
/// @param var (char *) Name of variable to unset
/// @param envp (char **) The enviroment where to unset
/// @return int
int	unset(t_Token *arguments, int arg_count)
{
	int	index;

	index = 0;
	while (index < arg_count)
		remove_environ(arguments[index++].lexeme);
	return (0);
}

/// Exits the Shell and cleans up the remainders
/// @param to_clean (void *) Pointer to anything that needs to be cleaned
/// when exitin the shell. When nothing to clear pass NULL
/// @return (void) No return.
int	custom_exit(t_Command *c)
{
	int	exit_code;

	if (c != NULL && c->arg_count != 0)
	{
		if (c->arg_count >= 2)
		{
			if (is_number(c->arguments[0].lexeme))
				return (printf("exit: too many arguments\n"),
					add_environ(ft_strjoin_free(ft_strdup("?="),
							ft_strdup("1"))), 0);
			else
				return (printf("exit: %s: numeric argument required\n",
						c->arguments[0].lexeme), ft_vecfree(enviroment(NULL)),
					exit(255), 0);
		}
		if (c->arg_count == 1 && !is_number(c->arguments[0].lexeme))
			return (printf("exit: %s: numeric argument required\n",
					c->arguments[0].lexeme), ft_vecfree(enviroment(NULL)),
				exit(255), 0);
			exit_code = ft_atoi(c->arguments[0].lexeme);
		return (ft_vecfree(enviroment(NULL)), exit(exit_code), 0);
	}
	return (ft_vecfree(enviroment(NULL)), exit(0), 0);
}
