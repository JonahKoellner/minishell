/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:22:25 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/21 16:50:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n > 0)
		n *= -1;
	if (n % 10 == 0)
		n--;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*makea(int n, int i, char *toa)
{
	if (n >= 10)
	{
		toa[i--] = n % 10 + 48;
		makea(n / 10, i, toa);
	}
	else
		toa[i--] = n + 48;
	return (toa);
}

char	*ft_itoa(int n)
{
	char	*toa;
	int		i;

	i = 0;
	i = intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	toa = malloc(sizeof(char *) * (i));
	if (!toa)
		return (0);
	if (n < 0)
	{
		toa[0] = '-';
		n *= -1;
	}
	toa[i--] = 0;
	toa = makea(n, i, toa);
	return (toa);
}
