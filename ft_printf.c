/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:28:39 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/09 17:43:25 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		printed_len;
	int		d;
	va_list	ap;
	va_list	ap2;

	char c, *s;
	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
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
