/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/30 15:39:17 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Change Path of Current Working Directory
/// @param path (char *) The Directory to change to.
/// @return Return Value from chdir (lib function).
int	cd(char *path)
{
	int		cd_ret;
	char	*home;

	if (!path)
	{
		home = var_search("HOME");
		chdir(home);
		free(home);
		return (0);
	}
	cd_ret = chdir(path);
	if (cd_ret == -1)
		perror("chdir");
		// printf("cd: no such file or directory: %s\n", path);
	return (0);
}

/// Print the current working Directory
/// @param void (void) No Parameter.
/// @return Returns 0 on success, no failure catched for now.
int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (perror("getcwd"), 1);
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}

/// Check if file exists or create it
/// @param path (char *) Path to the file.
/// @return Returns an error code. -1 == doesnt exist, -2
/// not given rights, 0 == ok
int	check_file(char *path, int rights)
{
	if (!path)
		return (0);
	if (access(path, 0) == -1)
		return (-1);
	if (access(path, rights) == -1)
		return (-2);
	return (0);
}
