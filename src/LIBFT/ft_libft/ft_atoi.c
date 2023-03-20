/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:48:54 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/20 14:54:26 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
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

int	ft_atoi(const char *str)
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
	return (res_sign * res);
}

/*
int main()
{
	char str[] = "\t \n 6514";
	printf("%i\n", ft_atoi(str));
	printf("%i", ft_atoi(str)):
}
*/
