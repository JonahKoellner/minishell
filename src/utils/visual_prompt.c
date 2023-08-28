/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:47:20 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/28 13:18:08 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Prints a new line of the shell, with string appended
/// @param string (char *) String to append after the minishell standard line.
/// @return Returns 0 on success, no failure catched for now.
///
char	*new_line(void)
{
	char	*pwd;
	char	*prefix;

	prefix = ft_strdup("\e[0;32mminishell> \e[0;94m");
	pwd = getcwd(NULL, 0);
	prefix = ft_strjoin_free(prefix, pwd);
	return (ft_strjoin_free(prefix, ft_strdup("\e[0m:$ ")));
}
