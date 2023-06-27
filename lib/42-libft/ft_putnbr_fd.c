/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:59:39 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/28 17:37:28 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int i)
{
	if (-2147483648 == n)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		i++;
	}
	if (n >= 10)
		i += ft_putnbr_fd(n / 10, fd, 1);
	ft_putchar_fd((n % 10) + '0', fd);
	return (i);
}
