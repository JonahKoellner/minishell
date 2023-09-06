/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/09/06 15:21:18 by jkollner         ###   ########.fr       */
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
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = ft_strjoin_free(ft_strdup("OLDPWD="), getcwd(NULL, 0));
	home = var_search(ft_strdup("HOME"));
	if (!path)
		cd_ret = chdir(home);
	else
		cd_ret = chdir(path);
	new_pwd = ft_strjoin_free(ft_strdup("PWD="), getcwd(NULL, 0));
	if (cd_ret)
		perror("chdir");
	else
	{
		add_environ(new_pwd);
		add_environ(old_pwd);
	}
	return (free(home), 0);
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
	printf("%s\n", pwd);
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
