/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:15:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 06:38:42 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft.h"

/// @brief Outputs the integer \p [n] to the file descriptor \p [fd]
/// @param n The integer to output.
/// @param fd The file descriptor to write to.
/// @param i Counter for written decimals. Always call with i = 1.
/// @return Returns number of written decimals.
static int	ft_put_count_nbr_fd(int n, int fd, int i)
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
		i += ft_put_count_nbr_fd(n / 10, fd, 1);
	ft_putchar_fd((n % 10) + '0', fd);
	return (i);
}

static int	ft_print_uphex(unsigned int n, int count, int base, int fd)
{
	const char	*uphex = "0123456789ABCDEF";

	if (n >= (unsigned)base)
		count += ft_print_uphex(n / base, 1, base, fd);
	ft_putchar_fd(uphex[n % base], fd);
	return (count);
}

static int	ft_print_hex(unsigned int n, int count, int base, int fd)
{
	const char	*hex = "0123456789abcdef";

	if (n >= (unsigned)base)
		count += ft_print_hex(n / base, 1, base, fd);
	ft_putchar_fd(hex[n % base], fd);
	return (count);
}

static int	ft_checkflag(va_list arg, char flag, int fd)
{
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(arg, int), fd));
	else if (flag == 's')
		return (ft_putstr_fd(va_arg(arg, char *), fd));
	else if (flag == 'i' || flag == 'd')
		return (ft_put_count_nbr_fd (va_arg(arg, int), fd, 1));
	else if (flag == 'u')
		return (ft_print_hex(va_arg(arg, unsigned int), 1, 10, fd));
	else if (flag == 'x')
		return (ft_print_hex(va_arg(arg, unsigned int), 1, 16, fd));
	else if (flag == 'p')
	{
		ft_putstr_fd("0x", fd);
		return (ft_print_hex(va_arg(arg, unsigned long), 3, 16, fd));
	}
	else if (flag == 'X')
		return (ft_print_uphex(va_arg(arg, unsigned int), 1, 16, fd));
	else if (flag == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
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
			ft_putchar_fd(flags[i++], fd);
			len++;
		}
		if (flags[i])
			len += ft_checkflag(arg, flags[++i], fd);
		if (flags[i])
			i++;
	}
	va_end(arg);
	return (len);
}
