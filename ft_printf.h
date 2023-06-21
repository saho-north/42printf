/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:33:21 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 03:38:34 by sakitaha         ###   ########.fr       */
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
ssize_t	ft_putchar_fd_count(char c, int fd);
ssize_t	ft_putstr_fd_count(char *s, int fd);
ssize_t	ft_putnbr_fd_base_count(int n, const char *base, int fd);
ssize_t	ft_putnbr_fd_bc_ul(unsigned long num, const char *base, int fd);
ssize_t	ft_putptr_fd_count(void *ptr, int fd);
ssize_t	ft_puthex_fd_count(unsigned int n, int fd, bool is_upper);
size_t	ft_strlen(const char *str);

#endif
