/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:20 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/09 15:49:05 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints a new line of the shell, with string appended
 *
 * @param string (char *) String to append after the minishell standard line.
 * @return Returns 0 on success, no failure catched for now.
 */
int	new_line(char *string)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	printf("minishell>%s:$ %s", pwd, string);
	free(pwd);
	return (0);
}
