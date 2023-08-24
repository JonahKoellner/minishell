/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:58:19 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/24 15:45:27 by mreidenb         ###   ########.fr       */
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
	printf("%s", string);
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
 * Prints the history of commands
 * @param void (void) No Parameter.
 * @return Returns 0 on success, no failure catched for now.
 */
//int	print_history(void)
//{
//	HIST_ENTRY		**hist;
//	HISTORY_STATE	*hist_state;
//	int				index;

//	hist = history_get(0);
//	hist_state = history_get_history_state();
//	index = 0;
//	while (index < hist_state->length)
//	{
//		printf("\t%d\t%s\n", index + 1, hist[index]->line);
//		index++;
//	}
//	return (0);
//}
