/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:54:19 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/21 21:42:56 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_count(char *s, int fd)
{
	if (!s)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}
