/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:20 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/27 15:14:41 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	new_line()
{
	char	*pwd;

	/*
	If buf is NULL, space is allocated as necessary to store the pathname and size is
	ignored.  This space may later be free(3)'d.
	*/
	pwd = getcwd(NULL, 0);
	printf("minishell>%s:$ ", pwd);
	free(pwd);
	return (0);
}
