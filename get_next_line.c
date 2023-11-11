/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:09:28 by passunca          #+#    #+#             */
/*   Updated: 2023/11/11 22:23:13 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	

}
