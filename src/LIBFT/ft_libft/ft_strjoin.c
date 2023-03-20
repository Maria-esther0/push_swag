/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:57 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/22 15:03:32 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	str1;
	size_t	str2;

	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	s = malloc(sizeof(*s) * (str1 + str2 + 1));
	if (s != NULL)
	{
		ft_memcpy(s, s1, str1);
		ft_memcpy(s + str1, s2, str2);
		s[str1 + str2] = '\0';
	}
	return (s);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	str1;
	size_t	str2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	s = malloc (((str1 + str2) + 1) * sizeof(char));
	str1 = 0;
	str2 = 0;
	while (s1[str1])
	{
		s[str1] = s1[str1];
		str1++;
	}
	while (s2[str2])
	{	
		s[str1 + str2] = s2[str2];
		str2++;
	}
	s[str1 + str2] = '\0';
	return (s);
}*/
/*
int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	char *s;

	s = ft_strjoin("je", "suis");
	printf("%s\n", s);
	
	return (0);
}*/
