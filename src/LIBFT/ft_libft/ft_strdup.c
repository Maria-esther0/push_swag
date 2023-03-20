/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:22:59 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/11 14:53:29 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newstr;

	newstr = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!newstr)
		return (0);
	return ((char *)ft_memcpy(newstr, s1, ft_strlen(s1) + 1));
}
