/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:28:39 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/14 23:18:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
#
「別の形式」に変換する時に使う。その機能は、変換指定子によって変わってくる。
oi換では、先頭に0を追加する。
x、X変換では、値が0でない時には、先頭に0xまたは0Xを追加する。

%[フラグ][最小フィールド幅].[精度][長さ修飾子][変換指定子]
cspdiuxX%
*/

static ssize_t	format(const char *fmt, va_list ap)
{
	if (*fmt == 'c')
	{
		return (ft_putchar_fd_count(va_arg(ap, int), 1));
	}
	else if (*fmt == 's')
	{
		return (ft_putstr_fd_count(va_arg(ap, char *), 1));
	}
	else if (*fmt == 'p')
	{
		return (ft_putptr_fd_count(va_arg(ap, void *), 1));
	}
	else if (*fmt == 'd' || *fmt == 'i')
	{
		return (ft_putnbr_fd_base_count(va_arg(ap, int), "0123456789", 1));
	}
	else if (*fmt == 'u')
	{
		return (ft_putnbr_fd_bc_unsigned(va_arg(ap, unsigned int), "0123456789",
				1));
	}
	else if (*fmt == 'x')
	{
		return (ft_putnbr_fd_bc_unsigned(va_arg(ap, unsigned int),
											"0123456789abcdef",
											1));
	}
	else if (*fmt == 'X')
	{
		return (ft_putnbr_fd_bc_unsigned(va_arg(ap, unsigned int),
											"0123456789ABCDEF",
											1));
	}
	else if (*fmt == '%')
	{
		return (ft_putchar_fd_count('%', 1));
	}
	else
	{
		return (ERROR);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	printed_len;
	ssize_t	check_res;

	printed_len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '\0')
				return (ERROR);
			check_res = format(fmt, ap);
		}
		else
		{
			check_res = ft_putchar_fd_count(*fmt, 1);
		}
		if (check_res < 0)
			return (-1);
		printed_len += check_res;
		fmt++;
	}
	va_end(ap);
	return ((int)printed_len);
}
