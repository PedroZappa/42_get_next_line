/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/20 19:49:20 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getline(int fd, char *substr);
static void	ft_gettillnl(char *vault);
static void	ft_getrest(char *vault);

char	*get_next_line(int fd)
{
	static char	*vault;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	vault = ft_getline(fd, &vault);
	if (!vault)
		return (NULL);
	line = ft_gettillnl(&vault);
	vault = ft_getrest(&vault);
	return (line);
}

/* Read BUFFER_SIZE bytes from 'fd' and store in 'vault'
 * */
static int	ft_getline(int fd, char *substr)
{
}

/*	Get line terminate by '\n' from 'vault'
 * */
static void	ft_gettillnl(char *vault)
{
}

/*	Clear already printed chars in 'vault'
 * */
static void	ft_getrest(char **vault)
{
}
