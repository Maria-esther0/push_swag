/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:38:27 by mvillarr          #+#    #+#             */
/*   Updated: 2023/01/05 14:11:01 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;
	int		len;

	len = ft_strlen(s1);
	i = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		x;

	i = 0;
	x = 0;
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[x] = s1[i];
		i++;
		x++;
	}
	i = 0;
	while (s2[i])
	{
		s[x] = s2[i];
		i++;
		x++;
	}
	s[x] = 0;
	free ((void *)(s1));
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			a;

	a = (char) c;
	i = 0;
	while (s[i])
	{		
		if (s[i] == a)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
		return (malloc(1));
	else if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len) + 1);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
