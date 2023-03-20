/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:07:15 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/15 15:11:54 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			a;

	a = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
		{
			return ((char *) &s [i]);
		}
		i++;
	}
	if (s[i] == a)
		return ((char *) &s[i]);
	return (NULL);
}
