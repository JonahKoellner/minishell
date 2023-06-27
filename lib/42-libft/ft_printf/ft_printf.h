/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:35:23 by mreidenb          #+#    #+#             */
/*   Updated: 2023/05/09 17:00:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
char	*ft_convert(unsigned int num, int base, char flag);
int		ft_checkflag(va_list arg, char flag);
int		ft_print_hex(unsigned int n, int count, int base);
int		ft_print_uphex(unsigned int n, int count, int base);

#endif