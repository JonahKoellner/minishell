/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:20 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/02 12:57:34 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	new_line(char *string)
{
	char	*pwd;

	/*
	If buf is NULL, space is allocated as necessary to store the pathname and size is
	ignored.  This space may later be free(3)'d.
	*/
	pwd = getcwd(NULL, 0);
	printf("minishell>%s:$ %s", pwd, string);
	free(pwd);
	return (0);
}
