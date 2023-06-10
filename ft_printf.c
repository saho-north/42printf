/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:28:39 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/10 10:08:24 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_format(char *fmt, va_list ap)
{
	if (*fmt == 'c')
		print_char(va_arg(ap, int));
	else if (*fmt == 's')
		print_string(va_arg(ap, char *));
	else if (*fmt == 'p')
		print_pointer(va_arg(ap, void *));
	else if (*fmt == 'd')
		print_int(va_arg(ap, int));
	else if (*fmt == 'i')
		print_int(va_arg(ap, int));
	else if (*fmt == 'u')
		print_unsigned_int(va_arg(ap, unsigned int));
	else if (*fmt == 'x')
		print_hex(va_arg(ap, unsigned int));
	else if (*fmt == 'X')
		print_hex_upper(va_arg(ap, unsigned int));
	else if (*fmt == '%')
		print_char('%');
}

int	ft_printf(const char *fmt, ...)
{
	int		printed_len;
	int		d;
	va_list	ap;

	char c, *s;
	va_start(ap, fmt);
	while (*fmt)
	{
	}
	switch (*fmt++)
	{
	case 's': /* string */
		s = va_arg(ap, char *);
		printf("string %s\n", s);
		break ;
	case 'd': /* int */
		d = va_arg(ap, int);
		printf("int %d\n", d);
		break ;
	case 'c': /* char */
		/* Note: char is promoted to int. */
		c = va_arg(ap, int);
		printf("char %c\n", c);
		break ;
	}
	va_end(ap);
	/* use ap2 to iterate over the arguments again */
	va_end(ap2);
}
