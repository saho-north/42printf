/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:30:14 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/14 17:29:47 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	format_specifier(const char specifier, va_list *ap)
{
	if (specifier == 'c')
		return (ft_putchar_count(va_arg(*ap, int)));
	else if (specifier == 's')
		return (ft_putstr_count(va_arg(*ap, char *)));
	else if (specifier == 'p')
		return (ft_putptr_count(va_arg(*ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_base_count(va_arg(*ap, int), "0123456789"));
	else if (specifier == 'u')
		return (ft_putnbr_ul_base_count(va_arg(*ap, unsigned int),
										"0123456789"));
	else if (specifier == 'x')
		return (ft_puthex_count(va_arg(*ap, unsigned int), IS_LOWER));
	else if (specifier == 'X')
		return (ft_puthex_count(va_arg(*ap, unsigned int), IS_UPPER));
	else if (specifier == '%')
		return (ft_putchar_count('%'));
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
			check_res = ft_putchar_count(*fmt);
		if (check_res < 0)
			return (-1);
		printed_len += check_res;
		fmt++;
	}
	va_end(ap);
	return ((int)printed_len);
}
