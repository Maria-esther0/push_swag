/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:52:36 by mvillarr          #+#    #+#             */
/*   Updated: 2022/11/23 18:07:09 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	ft_number_words(const char *str, char c)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			number++;
		}
	}
	return (number);
}

static char	*ft_print_word(const char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	word[i] = 0;
	while (0 < i--)
		word[i] = s[i];
	return (word);
}

static void	*ft_clean(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	word_i;
	size_t	word_nb;
	size_t	i;

	word_i = 0;
	word_nb = ft_number_words(s, c);
	i = 0;
	tab = ft_calloc((word_nb + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (word_i < word_nb)
	{
		if (s[i] != c)
		{
			tab[word_i] = ft_print_word(s + i, c);
			if (!tab[word_i])
				return (ft_clean(tab));
			i += ft_strlen(tab[word_i++]);
		}
		else
			i++;
	}
	tab[word_nb] = 0;
	return (tab);
}

/*
static int	nb_char(const char *str, char c)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	while (*str)
	{
		if (*str != c && sep == 0)
		{
			sep = 1;
			i++;
		}
		else if (*str == c)
			sep = 0;
		str++;
	}
	return (i);
}

static char	*word_cpy(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (0);
	split = malloc((nb_char(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_cpy(s, index, i);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}

int main()
{
	char str[20] = "This is string.";
	char **result = ft_split(str, 'r');
	printf("The result is %s\n", *result);
	printf("The result is %s\n", result[0]);
	printf("The result is %s\n", result[1]);
	return 0;
}*/
