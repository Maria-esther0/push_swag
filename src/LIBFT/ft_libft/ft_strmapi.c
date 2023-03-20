/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:02 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/11 16:48:11 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s || !f)
	{
		return (NULL);
	}
	ptr = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
	{
		return (NULL);
	}
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
char my_func(unsigned int i, char str)
{
	printf("My inner function: index = %d and %c\n", i, str);
 	return str - 32;
}

int main()
{
 	char str[15] = "coucou";
 	printf("The result is %s\n", str);
 	char *result = ft_strmapi(str, my_func);
 	printf("The result is %s\n", result);
 	return 0;
}*/
