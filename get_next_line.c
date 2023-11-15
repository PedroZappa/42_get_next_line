/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/15 15:22:06 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *input, char *line);
char	*ft_gettillnl(char *input);
char	*ft_getrest(char *input);

char *get_next_line(int fd)
{
	static char	input[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	// Other edge checks
	if (input[0] == '\0')
	{
		line = ft_gettillnl(input);
		ft_getrest(input);
		if (ft_strchr(input, '\n'))
			return (line);
	}
	line = ft_getline(fd, input, line);
	return (line);
}

/* Read from file descriptor and store it in 'input'
 * Join 'substr's into 'line' until '\n' is found */
char	*ft_getline(int fd, char *input, char *line)
{
	int c_read;

	c_read = (int)read(fd, input, BUFFER_SIZE);	
	while (c_read > 0)
	{
		line = ft_strjoin(line, ft_gettillnl(input));
		input = ft_getrest(input);
		if (ft_strchr(input, '\n'))
			return (line);
		c_read = (int)read(fd, input, BUFFER_SIZE);
	}
	if (!input)
		return (NULL);
	return (line);
}

/* Copy 'substr's into 'line' until '\n' is found */
char	*ft_gettillnl(char *input)
{
	int		i;
	char	*line;

	i = 0;
	while (input[i] && (input[i] != '\n'))
		++i;
	if (input[i] == '\n')
		++i;
	line = malloc(sizeof(char) * (i + 1));
	line[i] = '\0';
	while (i-- > 0)
		line[i] = input[i];
	return (line);
}

/* Save the rest of 'input' after '\n' */
char	*ft_getrest(char *input)
{
	int		i;
	int		j;

	i = 0;
	while (input[i] && (input[i] != '\n'))
		++i;
	if (input[i] == '\n')
		++i;
	j = 0;
	while (input[i])
		input[j++] = input[i++];
	while (input[j])
		input[j] = '\0';
	return (input);
}
