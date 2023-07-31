/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:08:35 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/20 19:54:44 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quote(char *command, int *i)
{
	int		start;
	char	c;

	start = *i;
	c = command[start];
	while (command[*i] != c)
	{
		if(command[*i] == '\0')
		{
			return (NULL);
		}
		*i++;
	}
	return (fillstr(command, start + 1, *i - 1));
}
