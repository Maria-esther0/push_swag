/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:49:35 by mvillarr          #+#    #+#             */
/*   Updated: 2022/12/06 15:16:39 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_check_type(const char type, va_list args);
int	ft_put_c(char c);
int	ft_put_d_i(long nb);
int	ft_put_p(void *arg);
int	ft_put_s(char *str);
int	ft_put_u(unsigned int nb);
int	ft_put_x(unsigned long int nb, unsigned int type);
int	ft_base16(unsigned long nb, char *alpha);
int	ft_putchar(char c);

#endif
