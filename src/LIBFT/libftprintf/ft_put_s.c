/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:10:18 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/06 15:13:43 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_s(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = ("(null)");
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	if (i < 0)
		return (-1);
	return (i);
}
