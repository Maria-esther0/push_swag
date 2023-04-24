/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:05:48 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/24 16:06:35 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	char_to_int(char c)
{
	return (c - '0');
}

static int	space(char c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int	my_atoi(const char *str, int *ret)
{
	int	res;
	int	res_sign;

	res = 0;
	res_sign = 1;
	while (space(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			res_sign *= -1;
		str++;
	}
	while (number (*str))
	{
		res *= 10;
		res += char_to_int(*str);
		str++;
	}
	if (number(*str))
		return (1);
	*ret = res_sign * res;
	return (*ret);
}
