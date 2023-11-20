/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/20 19:59:50 by passunca         ###   ########.fr       */
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

}

/*	Clear already printed chars in 'vault'
 * */
static char		*ft_getrest(char **vault)
{
}
