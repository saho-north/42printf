/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:32:57 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 02:01:51 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			ch;
	char			*str;
	int				num;
	unsigned int	u_num;

	ch = 'A';
	str = "Hello, world!";
	num = -42;
	u_num = 424242;
	ft_printf("ft_printf: %c %s %d %u\n", ch, str, num, u_num);
	printf("printf   : %c %s %d %u\n", ch, str, num, u_num);
	// ft_printf("ft_printf: %d %p %s\n", num, (void *)&num, str);
	// printf("printf   : %d %p %s\n", num, (void *)&num, str);
	return (0);
}
