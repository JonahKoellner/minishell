/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:08:37 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/07 10:09:21 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_number(char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (1);
	while (index < (int)ft_strlen(str))
	{
		if (str[index] > 57 || str[index] < 48)
			return (0);
		index++;
	}
	return (1);
}

int	check_char(char *str, char c)
{
	int	index;

	index = 0;
	if (str[index] == 0x00)
		return (0);
	while (str[index])
	{
		if (str[index++] != c)
			return (0);
	}
	return (1);
}
