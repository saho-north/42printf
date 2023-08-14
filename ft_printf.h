/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:33:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/14 17:29:47 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

# define IS_UPPER 1
# define IS_LOWER 0

int		ft_printf(const char *format, ...);
ssize_t	ft_putchar_count(char c);
ssize_t	ft_putstr_count(char *s);
ssize_t	ft_putnbr_base_count(int n, const char *base);
ssize_t	ft_putnbr_ul_base_count(unsigned long num, const char *base);
ssize_t	ft_putptr_count(void *ptr);
ssize_t	ft_puthex_count(unsigned int n, bool is_upper);
size_t	ft_strlen(const char *str);

#endif
