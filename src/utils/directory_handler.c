/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/18 13:44:22 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Change Path of Current Working Directory
 *
 * @param path (char *) The Directory to change to.
 * @return Return Value from chdir (lib function).
 */
int	cd(char *path)
{
	if (!path)
		return (chdir("~"));
	return (chdir(path));
}

/**
 * Print the current working Directory
 *
 * @param void (void) No Parameter.
 * @return Returns 0 on success, no failure catched for now.
 */
int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf("\n%s\n", pwd);
	free(pwd);
	return (0);
}

/**
 * Check if file exists or create it
 *
 * @param path (char *) Path to the file.
 * @return Returns an error code. -1 == doesnt exist, -2 not given rights, 0 == ok
*/
int	check_file(char *path, int rights)
{
	if (!path)
		return (0);
	if (open(path, 0) == -1)
		return (-1);
	if (open(path, rights) == -1)
		return (-2);
	return (0);
}
