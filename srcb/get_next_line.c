/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/21 15:17:50 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *vault);
static char	*ft_getline(char *vault);
static char	*ft_getrest(char *vault);

/// @brief		Get next line from 'fd'
/// @param fd	File descriptor
/// @return		Pointer to a string
char	*get_next_line(int fd)
{
	static char	*vault;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!vault)
	{
		vault = malloc(1);
		vault[0] = '\0';
	}
	vault = ft_read(fd, vault);
	if (!vault)
		return (NULL);
	line = ft_getline(vault);
	vault = ft_getrest(vault);
	return (line);
}

/// @brief			Read BUFFER_SIZE bytes from 'fd' and store in 'vault'
/// @param fd		File descriptor
/// @param vault	Pointer to the storage vault
/// @return			Pointer to the filled storage vault
static char	*ft_read(int fd, char *vault)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(vault, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(vault);
			vault = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		vault = ft_strjoin_gnl(vault, buffer);
	}
	free(buffer);
	return (vault);
}

/// @brief			Extract line terminated by '\n' from 'vault'
/// @param vault	Pointer to the storage vault
/// @return			Pointer to the line
static char	*ft_getline(char *vault)
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

/// @brief			Clear extracted chars from 'vault' keeping only the rest
/// @param vault	Pointer to the storage vault
/// @return			Pointer to what is left in the storage vault
static char	*ft_getrest(char *vault)
{
	int		i;
	int		rest_i;
	char	*rest;

	i = 0;
	while (vault[i] && (vault[i] != '\n'))
		++i;
	if (!vault[i])
	{
		free(vault);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen_gnl(vault) - i + 1));
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	++i;
	rest_i = 0;
	while (vault[i])
		rest[rest_i++] = vault[i++];
	rest[rest_i] = '\0';
	free(vault);
	return (rest);
}
