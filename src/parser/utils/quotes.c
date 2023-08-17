/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:08:35 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 06:54:20 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quote(char *command, int *i)
{
	int		start;
	char	c;

	if (command[*i] != '\"' && command[*i] != '\'')
		return (command);
	start = *i + 1;
	c = command[start];
	while (command[*i] != c)
	{
		if (command[*i] == '\0')
		{
			return (NULL);
		}
		*i++;
	}
	return (ft_substr(command, start, *i - start));
}
