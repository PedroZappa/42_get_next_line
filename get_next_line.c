/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:09:28 by passunca          #+#    #+#             */
/*   Updated: 2023/11/11 23:44:54 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_getline(int fd, t_list **strs, int *c_read);
int		ft_isnewline(t_list *strs);
void	ft_storestr(t_list **strs, char *buffer, int c_read);

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

	while (!ft_isnewline(*strs) && *c_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		*c_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!*strs && *c_read == 0) || (*c_read == -1))
		{
			free(buffer);
			return ;
		}
		buffer[*c_read] = '\0';
		ft_storestr(strs, buffer, *c_read);
		free(buffer);	
	}
	return ;
}

void ft_storestr(t_list **strs, char *buffer, int c_read)
{
	int		i;
	t_list	*last_str;
	t_list	*new_str;

	new_str = malloc(sizeof(t_list));
	if (!new_str)
		return ;
	new_str->next = NULL;
	new_str->str = malloc(sizeof(char) * (c_read + 1));
	if (!new_str->str)
		return ;
	i = 0;
	while (buffer[i] && (i < c_read))
	{
		new_str->str[i] = buffer[i];
		++i;
	}
	new_str->str[i] = '\0';
	if (!*strs)
	{
		*strs = new_str;
		return ;
	}
	last_str = ft_getlastnode(*strs);
	last_str->next = new_str;
}
