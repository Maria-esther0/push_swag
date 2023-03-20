/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:45 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/07 11:35:23 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start (args, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (!str[i])
			return (0);
		if (str[i] == '%' && str[i++])
			counter += ft_check_type(str[i], args);
		else if (str[i] != '%')
			counter += ft_put_c(str[i]);
		i++;
	}
	va_end(args);
	if (counter < 0)
		return (-1);
	return (counter);
}
/*int result = printf("Sentence to know how many %s\n",
 * "characters were written");
    printf("%d characters were written", result);
    return (0);*/
// in C language,, *p represents the value stored in a pointer and p represents
// the address of the value. const char* says that the pointer can point to a 
// constant char value of a char pointed by this pointer cannot be changed.