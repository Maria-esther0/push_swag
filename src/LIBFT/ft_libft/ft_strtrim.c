/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:32:55 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/11 16:51:33 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i - 1]))
	{
		i--;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	return (str);
}
/*
int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	printf("%s", ft_strtrim("abcdba", "abc"));
	return (0);
}*/
