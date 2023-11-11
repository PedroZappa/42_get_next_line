/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:09:28 by passunca          #+#    #+#             */
/*   Updated: 2023/11/11 22:56:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_getline(int fd, t_list **strs, int *c_read);
int		ft_isnewline(t_list *strs);

char	*get_next_line(int fd)
{
	static t_list	*strs;
	char			*line;
	int				c_read;

	strs = NULL;
	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, &line, 0) < 0)
		return (NULL);
	c_read = 1;
	line = NULL;
	ft_getline(fd, &strs, &c_read);
	if (!strs)
		return (NULL);
	
	return (line);
}

void	ft_getline(int fd, t_list **strs, int *c_read)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	while (!ft_isnewline(*strs) && *c_read != 0)
	{
		*c_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!*strs && *c_read == 0) || (*c_read == -1))
		{
			free(buffer);
			return ;
		}
		buffer[*c_read] = '\0';
	}


	
	return ;
}

int ft_isnewline(t_list *strs)
{

	return (0);
}
