/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:08:53 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/06 15:15:45 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += (char)ft_put_c(va_arg(args, int));
	else if (type == 's')
		count += ft_put_s(va_arg(args, char *));
	else if (type == 'p')
		count += ft_put_p(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count += ft_put_d_i(va_arg(args, int));
	else if (type == 'X' || type == 'x')
		count += (char)ft_put_x(va_arg(args, unsigned int), type);
	else if (type == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	else if (type == '%')
		return (write(1, "%", 1));
	return (count);
}
