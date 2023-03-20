/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:08:41 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/04 13:12:30 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*z;
	char			x;

	x = (char) c;
	z = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			z = (char *) &s[i];
		i++;
	}
	if (s[i] == x)
		z = (char *) &s[i];
	return (z);
}
