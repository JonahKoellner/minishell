/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:58:19 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/21 09:48:20 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Build in Function Echo
 * Prints given string with or without new line
 *
 * @param string (char *) String to be printed.
 * @param n_flag (int) New line flag (0 = no new line, 1 = new line)
 * @return Returns 0 on success, no failure catched for now.
 */
int	echo(char *string, int n_flag)
{
	printf("\n%s", string);
	if (n_flag)
	{
		printf("\n");
	}
	return (0);
}

/**
 * @brief Prints the enviroment variables taken from extern char**environ
 *
 * @param void (void) No Parameter.
 * @return Returns 0 on success, no failure catched for now.
 */
int	env(void)
{
	extern char	**environ;

	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}

/**
 * Exits the Shell and cleans up the remainders
 *
 * @param to_clean (void *) Pointer to anything that needs to be cleaned
 * when exitin the shell. When nothing to clear pass NULL
 * @return (void) No return.
 */
void	custom_exit(void *to_clean)
{
	if (to_clean)
		free(to_clean);
	exit(0);
}

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
int	execute_path(char *path, char *args, char **env_var)
{
	if (!path)
		return (1);
	//if (execve(path, args, env_var) == )
	(void)args;
	printf("executing in execute path\n");
	return (execve(path, NULL, env_var));
}
