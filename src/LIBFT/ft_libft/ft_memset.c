/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:30:18 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/04 13:09:58 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
ligne 23 la chaine de char commence des 0
ligne 25 tant que 0 est plus petit que la cantite de caises qu'on veur remplir,
ex2
*/
#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	z;
	unsigned char	*pointer1;
	size_t			i;

	pointer1 = (unsigned char *)pointer;
	z = (unsigned char)value;
	i = 0;
	while (i < count)
	{
		pointer1[i] = z;
		i++;
	}
	return (pointer1);
}
