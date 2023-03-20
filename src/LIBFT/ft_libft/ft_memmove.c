/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:20:11 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/04 13:10:50 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*temp1;
	unsigned char		*temp2;

	i = 0;
	temp1 = (const unsigned char *) src;
	temp2 = (unsigned char *) dst;
	if (temp1 == 0 && temp2 == 0)
		return (0);
	if (temp2 > temp1)
	{
		while (i < len)
		{
		temp2[len - i -1] = temp1[len - i -1];
		i++;
		}
	}
	while (i < len)
	{
		temp2[i] = temp1[i];
		i++;
	}
	return (dst);
}
