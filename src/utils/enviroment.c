/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:07:37 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 13:11:06 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// Setter and Getter Principle in one function
char	**enviroment(char	**envp)
{
	static char	**env;

	if (envp)
	{
		if (env != NULL)
			env = NULL;
		env = ft_vecdup(envp);
		ft_vecfree(envp);
	}
	return (env);
}

/// Add variable to the enviroment or update existing variable
/// Var contains the "equation" for the var (i.e: "HOME=/Users/")
int	add_environ(char	*var)
{
	if (!ft_vecreplace(var, enviroment(NULL)))
		enviroment(ft_vectoradd(enviroment(NULL), var));
	free(var);
	return (0);
}

int	remove_environ(char	*var)
{
	enviroment(ft_vecdelete(var, enviroment(NULL)));
	return (0);
}

char	*get_environ_item(char *item)
{
	char	**env;
	int		index;
	int		env_len;

	env = enviroment(NULL);
	index = 0;
	env_len = ft_veclen(env);
	while (index < env_len)
	{
		if (!(ft_strlen(env[index]) < ft_strlen(item)))
			if (!ft_strncmp(env[index], item, ft_strlen(item))
				&& env[index][ft_strlen(item)] == '=')
				return (ft_memchr(env[index], '=', ft_strlen(env[index])) + 1);
		index++;
	}
	return (NULL);
}
