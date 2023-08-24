/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:32:25 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/24 19:41:12 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_search(char *var, const char **env)
{
	int	i;
	int	env_len;
	int	var_len;

	i = 0;
	var_len = ft_strlen(var);
	env_len = ft_veclen(env);
	while (i < env_len)
	{
		if (ft_memcmp(env[i], var, var_len + 1) == '=')
		{
			free(var);
			return (ft_substr(env[i], var_len + 1,
					ft_strlen(env[i]) - (var_len + 1)));
		}
		i++;
	}
	return (free(var), ft_strdup(""));
}

char	*var_expander(char *input, char **env)
{
	char	*result;
	char	*tmp;
	size_t	e;
	size_t	i;

	i = 0;
	e = 0;
	result = ft_strdup("");
	while (i < ft_strlen(input))
	{
		e = i;
		if (input[i++] == '$')
		{
			e = i;
			while (!is_unquotable(input[i]))
				i++;
			tmp = var_search(ft_substr(input, e, i - e), env);
			result = ft_strjoin(result, tmp);
			free(tmp);
		}
		else
			result = ft_strjoin_free(result, ft_substr(input, e, i - e));
	}
	return (result);
}
