/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:15:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/09 17:00:19 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uphex(unsigned int n, int count, int base)
{
	const char	*uphex = "0123456789ABCDEF";

	if (n >= (unsigned)base)
		count += ft_print_uphex(n / base, 1, base);
	ft_putchar_fd(uphex[n % base], 1);
	return (count);
}

int	ft_print_hex(unsigned int n, int count, int base)
{
	const char	*hex = "0123456789abcdef";

	if (n >= (unsigned)base)
		count += ft_print_hex(n / base, 1, base);
	ft_putchar_fd(hex[n % base], 1);
	return (count);
}

int	ft_checkflag(va_list arg, char flag)
{
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (flag == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (flag == 'i' || flag == 'd')
		return (ft_putnbr_fd (va_arg(arg, int), 1, 1));
	else if (flag == 'u')
		return (ft_print_hex(va_arg(arg, unsigned int), 1, 10));
	else if (flag == 'x')
		return (ft_print_hex(va_arg(arg, unsigned int), 1, 16));
	else if (flag == 'p')
	{
		ft_putstr_fd("0x", 1);
		return (ft_print_hex(va_arg(arg, unsigned long), 3, 16));
	}
	else if (flag == 'X')
		return (ft_print_uphex(va_arg(arg, unsigned int), 1, 16));
	else if (flag == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	char	*flags;
	va_list	arg;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(arg, format);
	flags = (char *) format;
	while (flags[i] != '\0')
	{
		while (flags[i] != '%' && flags[i])
		{
			ft_putchar_fd(flags[i++], 1);
			len++;
		}
		if (flags[i])
			len += ft_checkflag(arg, flags[++i]);
		if (flags[i])
			i++;
	}
	va_end(arg);
	return (len);
}
