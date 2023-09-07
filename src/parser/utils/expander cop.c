/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:32:25 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/07 01:47:32 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_search(char *var)
{
	int		i;
	int		env_len;
	int		var_len;
	char	**env;

	i = 0;
	env = enviroment(NULL);
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
	free(var);
	return (ft_strdup(""));
}

char	*var_expander(char *input)
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
		if (input[i++] == '$' && is_unquotable(input[i]) != 1)
		{
			e = i;
			while (!is_unquotable(input[i]))
				i++;
			tmp = var_search(ft_substr(input, e, i - e));
			result = ft_strjoin_free(result, tmp);
		}
		else
			result = ft_strjoin_free(result, ft_substr(input, e, i - e));
	}
	free(input);
	return (result);
}

char	*replace_dollar(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
			input[i] = 6;
		i++;
	}
	return (input);
}

char	*finish_expand(char *res)
{
	int		i;

	i = 0;
	//res = var_expander(res);
	while (res[i])
	{
		if (res[i] == 6)
			res[i] = '$';
		i++;
	}
	return (res);
}

char	*expand_word(char *input)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	res = ft_strdup("");
	//printf("var_exp %s \n", input);
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			if (input[i] == '\"')
				tmp = var_expander(quote(input, &i));
			else if (input[i] == '\'')
				tmp = replace_dollar(quote(input, &i));
			res = ft_strjoin_free(var_expander(res), tmp);
		}
		else
		{
		tmp = ft_substr(input, i, 1);
		res = ft_strjoin_free(res, tmp);
		i++;
		}
	}
	free(input);
	return (finish_expand(res));
}
