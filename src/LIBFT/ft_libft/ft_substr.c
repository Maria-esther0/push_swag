/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:24:15 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/20 11:45:24 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (start + len > ft_strlen(s))
	{
		len = ft_strlen(s) - start;
	}
	str = malloc(sizeof(*str) * (len + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s + start, len);
		str[len] = '\0';
	}
	return (str);
}
/*
s: La chaîne de laquelle extraire la nouvelle
chaîne.
start: L’index de début de la nouvelle chaîne dans
la chaîne ’s’.
len: La taille maximale de la nouvelle chaîne.

int main(int ac, char **av)
{
	(void) ac;
	char *str;
	str = ft_substr(av[1], 3, 12);
	printf("%s\n", str);
	return (0);
}
	substr => array[8] = "je suis", indexe start = 3, longueur.

	int i = 0;
	int j = 0;
	int len;
	char *str; 

	while(array[i])
	{
		i++;
	}
	i = 8;
	len = i;
	str = (char *) malloc(sizeof(char *) * len + 1);	
	len => = 8
	i = 0;
	while (i != start)
	{
		i++;
	}
	i = 3;
	while(array[i])
	{
		str[j] = array[i]; 
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);

*/
