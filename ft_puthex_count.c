/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:32:53 by sakitaha          #+#    #+#             */
/*   Updated: 2023/06/22 04:06:25 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_puthex_count(unsigned int n, bool is_upper)
{
	if (is_upper)
	{
		return (ft_putnbr_ul_base_count(n, "0123456789ABCDEF"));
	}
	else
	{
		return (ft_putnbr_ul_base_count(n, "0123456789abcdef"));
	}
}
