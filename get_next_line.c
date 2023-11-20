/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/20 12:16:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getline(int fd, char **vault, char *substr);
static void	ft_gettillnl(char **vault, char **line);
static void	ft_clearvault(char **vault);

char	*get_next_line(int fd)
{
	// static char	*vault;
	static char	*vault = "";
	char		*substr;
	char		*line;
	int			c_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c_read = 1;
	substr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!substr)
		return (NULL);
	while (!ft_strchr(vault, '\n') && (c_read > 0))
		c_read = ft_getline(fd, &vault, substr);
	free(substr);
	if (c_read == -1 || (ft_strlen(vault) == 0))
		return (NULL);
	ft_gettillnl(&vault, &line);
	ft_clearvault(&vault);
	return (line);
}

/* Read BUFFER_SIZE bytes from 'fd' and store in 'vault'
 * */
static int	ft_getline(int fd, char **vault, char *substr)
{
	char	*line;
	int		c_read;

	ft_bzero(substr, (BUFFER_SIZE + 1));
	c_read = read(fd, substr, BUFFER_SIZE);
	if ((c_read < 0) || (substr == NULL))
	{
		free(*vault);
		*vault = NULL;
		return (-1);
	}
	if (c_read == 0)
		return (c_read);
	line = ft_strjoin(*vault, substr);
	*vault = line;
	return (c_read);
}

/*	Get line terminate by '\n' from 'vault'
 * */
static void	ft_gettillnl(char **vault, char **line)
{
	char	*newline;
	int		len;
	int		i;

	newline = ft_strchr(*vault, '\n');
	len = (ft_strlen(*vault) - ft_strlen(newline) + 2);
	*line = malloc(sizeof(char) * len);
	if (!line)
		return ;
	i = 0;
	while (i < (len - 1))
	{
		(*line)[i] = (*vault)[i];
		++i;
	}
	(*line)[i] = '\0';
}

/*	Clear already printed chars in 'vault'
 * */
static void	ft_clearvault(char **vault)
{
	int		i;
	int		del_i;
	char	*newline;
	char	*rest;

	newline = ft_strchr(*vault, '\n');
	if (!newline)
	{
		free(*vault);
		*vault = NULL;
		return ;
	}
	rest = malloc(sizeof(char) * (ft_strlen(*vault)));
	i = 0;
	del_i = (ft_strlen(*vault) - ft_strlen(newline) + 1);
	while (del_i  < ft_strlen(*vault))
		rest[i++] = (*vault)[del_i++];
	rest[i] = '\0';
	free(*vault);
	*vault = rest;
	if (**vault == '\0')
	{
		free(*vault);
		*vault = NULL;
	}
}
