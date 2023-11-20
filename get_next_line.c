/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/20 20:07:37 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_getline(int fd, char *vault);
static char	*ft_gettillnl(char *vault);
static char	*ft_getrest(char *vault);

char		*get_next_line(int fd)
{
	static char	*vault;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	vault = ft_getline(fd, vault);
	if (!vault)
		return (NULL);
	line = ft_gettillnl(vault);
	vault = ft_getrest(vault);
	return (line);
}

/* Read BUFFER_SIZE bytes from 'fd' and store in 'vault'
 * */
static char		*ft_getline(int fd, char *vault)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(*vault, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			free(vault);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		vault = ft_strjoin(vault, buffer);
	}
	free(buffer);
	return (vault);
}

/*	Get line terminate by '\n' from 'vault'
 * */
static char		*ft_gettillnl(char *vault)
{
	int		i;
	char	*line;

	i = 0;
	if (!vault[i])
		return (NULL);
	while (vault[i] && (vault[i] != '\n'))
		++i;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (vault[i] && (vault[i] != '\n'))
	{
		line[i] = vault[i];
		++i;
	}
	if (vault[i] == '\n')
	{
		line[i] = vault[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

/*	Clear already printed chars in 'vault'
 * */
static char		*ft_getrest(char *vault)
{
	int		i;
	int		pos;
	char	*rest;

	i = 0;
	while (vault[i] && (vault[i] != '\n'))
		++i;
	if (!vault[i])
	{
		free(vault);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(vault) - i + 1));
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	++i;
	pos = 0;
	while (vault[i])
		rest[pos++] = vault[i++];
	rest[pos] = '\0';
	free(vault);
	return (rest);
}
