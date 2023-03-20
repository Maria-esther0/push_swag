/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:17:48 by mvillarr          #+#    #+#             */
/*   Updated: 2023/01/06 11:47:01 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	stash = stash_filling(fd, stash, buffer);
	if (*stash == 0)
	{
		free(stash);
		return (stash = 0);
	}
	line = extract_line(stash, line);
	stash = extract_new_stash(stash);
	return (line);
}

char	*stash_filling(int fd, char *stash, char *buffer)
{
	ssize_t	n_bytes;

	n_bytes = 1;
	if (!stash)
		stash = ft_strdup("");
	while (n_bytes > 0)
	{
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n_bytes] = 0;
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			break ;
		}
	}
	free(buffer);
	return (stash);
}

char	*extract_new_stash(char *stash)
{
	int		len;
	int		i;
	char	*new_stash;

	if (stash == NULL)
		return (NULL);
	len = 0;
	while (stash[len] != '\n' && stash[len] != '\0')
		++len;
	if (stash[len] == '\n')
		++len;
	new_stash = malloc((ft_strlen(stash) - len + 1) * sizeof(char));
	if (!new_stash)
		return (NULL);
	new_stash[ft_strlen(stash) - len] = 0;
	i = 0;
	while (stash[len + i])
	{
		new_stash[i] = stash[len + i];
		i++;
	}
	free (stash);
	return (new_stash);
}

char	*extract_line(char *stash, char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[len] != '\n' && stash[len])
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc ((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = 0;
	return (line);
}
/*
int	main()
{	
	int fd;

	fd = open("text.txt", O_RDONLY);
	printf("GNL 1: %s", get_next_line(fd));
	printf("GNL 2: %s", get_next_line(fd));
	printf("GNL 3: %s", get_next_line(fd));
	printf("GNL 4: %s", get_next_line(fd));
	printf("GNL 5: %s", get_next_line(fd));
	printf("GNL 6: %s", get_next_line(fd));
	printf("GNL 7: %s", get_next_line(fd));
	printf("GNL 8: %s", get_next_line(fd));
	printf("GNL 9: %s", get_next_line(fd));
	close(fd);
}*/
