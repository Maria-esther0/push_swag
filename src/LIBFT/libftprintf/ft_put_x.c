/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:10:42 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/06 13:13:56 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(unsigned long int nb, unsigned int type)
{
	char	*a;

	if (type == 'x')
	{
		a = "0123456789abcdef";
	}
	else
	{
		a = "0123456789ABCDEF";
	}
	return (ft_base16(nb, a));
}

int	ft_base16(unsigned long nb, char *alpha)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_base16(nb / 16, alpha);
		count += ft_base16(nb % 16, alpha);
	}
	else if (count < 0)
	{
		return (-1);
	}
	else
	{
		count += ft_put_c (alpha[nb]);
	}
	return (count);
}
/*
char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
*/
