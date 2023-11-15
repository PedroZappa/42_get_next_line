/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/15 11:31:41 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *input, char *line);
char	*ft_gettillnl(char *input);

char *get_next_line(int fd)
{
	static char	input[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_getline(fd, input, line);
	return (line);
}

/* Read from file descriptor and store it in 'input'
 * Join 'substr's into 'line' until '\n' is found */
char	*ft_getline(int fd, char *input, char *line)
{
	int c_read;

	c_read = 1;
	c_read = (int)read(fd, input, BUFFER_SIZE);	
	while (c_read)
	{
		line = ft_strjoin(line, ft_gettillnl(input));
	}
	if (!input)
		return (NULL);
	return (line);
}

/* Join 'substr's into 'line' until '\n' is found */
char	*ft_gettillnl(char *input)
{
	int		i;
	char	*line;

	while (input[i] && input[i] != '\n')
		++i;
	if (input[i] == '\n')
		++i;
	line = malloc(sizeof(char) * (i + 1));
	line[i] = '\0';
	while (i--)
		line[i] = input[i];
	return (line);
}
