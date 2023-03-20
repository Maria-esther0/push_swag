/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:09:36 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/06 15:16:05 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_d_i(long nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483647)
	{
		write(1, "-2147483647", 11);
		counter = 11;
	}
	else if (nb < 0)
	{
		counter = counter + ft_put_c('-');
		counter = counter + ft_put_d_i(-nb);
	}
	else if (nb > 9)
	{
		counter = counter + ft_put_d_i(nb / 10);
		counter = counter + ft_put_d_i(nb % 10);
	}
	else if (counter < 0)
		return (-1);
	else
		counter = counter + ft_put_c(nb + '0');
	return (counter);
}
