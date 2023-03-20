/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:10:26 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/06 14:50:36 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int number)
{
	int	counter;

	counter = 0;
	if (number > 9)
	{
		counter = counter + ft_put_d_i(number / 10);
		counter = counter + ft_put_d_i(number % 10);
	}
	else if (number >= 0 && number < 10)
	{
		counter = counter + ft_put_c(number + '0');
	}
	else if (counter < 0)
	{
		return (-1);
	}
	return (counter);
}
