/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:30:14 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 04:06:17 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	format_specifier(const char specifier, va_list *ap)
{
	if (specifier == 'c')
		return (ft_putchar_fd_count(va_arg(*ap, int), 1));
	else if (specifier == 's')
		return (ft_putstr_fd_count(va_arg(*ap, char *), 1));
	else if (specifier == 'p')
		return (ft_putptr_fd_count(va_arg(*ap, void *), 1));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd_base_count(va_arg(*ap, int), "0123456789", 1));
	else if (specifier == 'u')
		return (ft_putnbr_ul_base_count(va_arg(*ap, unsigned int), "0123456789",
				1));
	else if (specifier == 'x')
		return (ft_puthex_fd_count(va_arg(*ap, unsigned int), 1, IS_LOWER));
	else if (specifier == 'X')
		return (ft_puthex_fd_count(va_arg(*ap, unsigned int), 1, IS_UPPER));
	else if (specifier == '%')
		return (ft_putchar_fd_count('%', 1));
	else
		return (-1);
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
			check_res = format_specifier(*fmt, &ap);
		}
		else
			check_res = ft_putchar_fd_count(*fmt, 1);
		if (check_res < 0)
			return (-1);
		printed_len += check_res;
		fmt++;
	}
	va_end(ap);
	return ((int)printed_len);
}
