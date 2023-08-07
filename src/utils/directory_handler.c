/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:50:45 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/08 00:13:44 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd(char *path)
{
	return (chdir(path));
}

int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf("\n%s\n", pwd);
	free(pwd);
	return (0);
}
