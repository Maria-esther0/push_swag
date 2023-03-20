/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:18:01 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/22 17:41:28 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		sign;
	size_t	index;
	size_t	length;

	index = 0;
	sign = 1;
	length = ft_intlen(n);
	result = malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = 0;
	if (n < 0)
	{
		result[index++] = '-';
		sign = -1;
	}
	while (index < length--)
	{
		result[length] = sign * (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

/*
static int	sizemalloc(int n)
{
	int	i;

	i = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = sizemalloc(n);
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == 0)
		return (NULL);
	ptr[i] = '\0';
	if (n < 0)
		ptr[0] = '-';
		n = n * -1;
	if (n == 0)
		ptr[0] = 48;
	while (n != '\0')
		ptr[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	return (ptr);
}

static int	ten_power(int nb)
{
	int	res;

	res = 1;
	while (nb--)
	{
		res *= 10;
	}
	return (res);
}

static int	digit_number(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		i;
	int		digit_nbr;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	nbr = (long)n;
	digit_nbr = digit_number(nbr);
	str = malloc(sizeof(*str) * (digit_nbr + 1));
	if (str != NULL)
	{
		i = 0;
		if (nbr < 0)
			str[i++] = '-';
		if (nbr > 0)
			nbr *= -1;
		while (i < digit_nbr)
		{
			str[i] = nbr / ten_power(digit_nbr - i - 1) + '0';
			nbr %= ten_power(digit_nbr - i++ - 1);
		}
		str[i] = 0;
	}
	return (str);
}

//Alloue (avec malloc(3)) et retourne une chaîne
//de caractères représentant l’entier ’n’ reçu en
//argument. Les nombres négatifs doivent être gérés.

//n: L’entier à convertir.

int main()
{
    printf("\nres:%s\n", ft_itoa(864694));
}
*/
