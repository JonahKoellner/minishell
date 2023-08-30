/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:07:37 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/30 10:51:02 by jkollner         ###   ########.fr       */
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
			//ft_vecfree(env);
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
	return (0);
}

int	remove_environ(char	*var)
{
	enviroment(ft_vecdelete(var, enviroment(NULL)));
	return (0);
}

//
//char	**env(char	**envp_org)
//{
//	static	char	**env;
//	int				env_len;
//
//	if (!env)
//	{
//		if (envp_org)
//		{
//			// allocate and copy env
//			env_len = ft_veclen(envp_org);
//			env = ft_calloc(env_len, sizeof(char *));
//			while (env_len)
//			{
//				env[env_len] = envp_org[env_len];
//				env_len--;
//			}
//
//		}
//	}
//	return (env);
//}
//
