/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:32:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 02:57:33 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_puthex_fd_count(unsigned int n, int fd, bool is_upper)
{
	if (is_upper)
	{
		return (ft_putnbr_fd_bc_ul(n, "0123456789ABCDEF", fd));
	}
	else
	{
		return (ft_putnbr_fd_bc_ul(n, "0123456789abcdef", fd));
	}
}
