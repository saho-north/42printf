/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:32:57 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/09 16:16:43 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		num;
	char	ch;
	char	*str;

	num = 42;
	ch = 'A';
	str = "Hello, world!";
	// ft_printfの出力と標準のprintfの出力を比較する
	ft_printf("ft_printf: %d %c %s\n", num, ch, str);
	printf("   printf: %d %c %s\n", num, ch, str);
	return (0);
}
