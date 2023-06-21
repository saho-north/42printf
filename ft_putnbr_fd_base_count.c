/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_base_count.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:55:30 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 00:18:20 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr_fd_bc_unsigned(unsigned long num, const char *base, int fd)
{
	ssize_t	ret;
	size_t	base_size;
	char	c;

	if (!base)
		return (-1);
	base_size = ft_strlen(base);
	if (num < base_size)
	{
		c = base[num];
		if (write(fd, &c, 1) < 0)
			return (-1);
		return (1);
	}
	ret = ft_putnbr_fd_bc_unsigned(num / base_size, base, fd);
	if (ret < 0)
		return (-1);
	c = base[num % base_size];
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (ret + 1);
}

ssize_t	ft_putnbr_fd_base_count(int n, const char *base, int fd)
{
	unsigned int	num;
	ssize_t			ret;
	bool			is_minus;

	if (n < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (-1);
		num = (unsigned long)((n + 1) * -1);
		num++;
		is_minus = true;
	}
	else
	{
		num = (unsigned long)n;
		is_minus = false;
	}
	ret = ft_putnbr_fd_bc_unsigned(num, base, fd);
	if (ret < 0)
		return (-1);
	if (is_minus)
		ret++;
	return (ret);
}
