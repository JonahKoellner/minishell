/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:42:26 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/18 03:12:24 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspaceplus(unsigned int c)
{
	if ((c >= 9 && 13 >= c) || c == 32 || c == '-' || c == '+')
		return (1);
	return (0);
}

static int	checkneg(const char *str)
{
	unsigned int	i;
	int				u;

	i = 0;
	u = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]) && !ft_isdigit(str[u]))
			return (-1);
		else if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			return (0);
		i++;
		u = i - 1;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		toi;

	i = 0;
	toi = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]) && str[i])
			{
				toi = toi + str[i] - 48;
				if (!ft_isdigit(str[i + 1]))
					return (toi * checkneg(str));
				toi *= 10;
				i++;
			}
		}
		if (!isspaceplus(str[i]))
			return (0);
		i++;
	}
	return (0);
}
