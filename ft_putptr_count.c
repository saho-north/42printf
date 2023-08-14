/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:48:40 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/14 17:28:00 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putptr_count(void *ptr)
{
	ssize_t	ret;

	if (!ptr)
		return (ft_putstr_count("0x0"));
	ret = ft_putstr_count("0x");
	if (ret < 0)
		return (-1);
	ret = ft_putnbr_ul_base_count((unsigned long)ptr, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	return (ret + 2);
}
