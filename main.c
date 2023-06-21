/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:32:57 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 03:07:08 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char			ch;
	char			*str;
	int				num;
	unsigned int	u_num;
	void			*ptr;

	ch = 'A';
	str = "Hello, world!";
	num = -42;
	u_num = 424242;
	ptr = &num;
	// Basic test cases
	ft_printf("ft_printf: %c %s %d %u\n", ch, str, num, u_num);
	printf("printf   : %c %s %d %u\n", ch, str, num, u_num);
	ft_printf("ft_printf: %d %p %s\n", num, ptr, str);
	printf("printf   : %d %p %s\n", num, ptr, str);
	// Edge cases
	str = ""; // empty string
	ft_printf("ft_printf: %s\n", str);
	printf("printf   : %s\n", str);
	num = INT_MAX; // max int
	ft_printf("ft_printf: %d\n", num);
	printf("printf   : %d\n", num);
	num = INT_MIN; // min int
	ft_printf("ft_printf: %d\n", num);
	printf("printf   : %d\n", num);
	u_num = UINT_MAX; // max unsigned int
	ft_printf("ft_printf: %u\n", u_num);
	printf("printf   : %u\n", u_num);
	// Additional format specifiers
	num = 42;
	ft_printf("ft_printf: %x\n", num); // lowercase hex
	printf("printf   : %x\n", num);
	ft_printf("ft_printf: %X\n", num); // uppercase hex
	printf("printf   : %X\n", num);
	return (0);
}
