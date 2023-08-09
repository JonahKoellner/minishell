/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/09 13:50:55 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
