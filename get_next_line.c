/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:19 by passunca          #+#    #+#             */
/*   Updated: 2023/11/16 09:20:29 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*vault;
	char		*buffer;
	char		*line;
	int			c_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while ((!ft_strchr(vault, '\n') && (c_read > 0)))
		c_read = ft_getline(fd, &vault, buffer);
	free(buffer);
	if (c_read < 0 || (ft_strlen(vault) == 0))
		return (NULL);
	return (line);

}

/* Initialize 'substr' with 'BUFFER_SIZE' bytes of '\0'
 * Read from file descriptor 'fd' into 'substr' 
 * Join 'substr's with 'vault' into 'line' 
 * Set 'vault' to 'line'
 * Return number of bytes read
 * */
int	ft_getline(int fd, char **vault, char *substr)
{
	char *line;
	int c_read;

	ft_bzero(substr, BUFFER_SIZE);
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
	free(*vault);
	*vault = line;
	return (c_read);
}

/*	Search through 'vault' for '\n', store result in 'nl'
 *		If not found, free 'vault', set it to NULL and return
 *	Allocate memory for 'line' to store the remaining chars after '\n'
 *	Get 'rest's length by calculating 'vault's length minus 'nl's length
 *	Copy chars after '\n' to 'rest'
 *	Set 'vault' to 'rest'
 *	If 'vault' is empty, free it and set it to NULL
 * */
void	ft_gettillnl(char **vault)
{
	int		i;
	int		j;
	char	*newline;
	char	*rest;

	newline = ft_strchr(*vault, '\n');
	if (!newline)
	{
		free(*vault);
		*vault = NULL;
		return ;
	}
	newline = malloc(sizeof(char) * (ft_strlen(*vault) + 1));
	i = 0;
	j = (ft_strlen(*vault) - ft_strlen(newline));
	while (j < ft_strlen(*vault))
		rest[i++] = (*vault)[j++];
	rest[i] = '\0';
	free(*vault);
	*vault = NULL;
	if (**vault == '\0')
	{
		free(*vault);
		*vault = NULL;
	}
}

/*  Save the rest of 'vault' after '\n' 
 * */
void	*ft_getrest(char **vault)
{
	int		i;
	int		j;

	i = 0;
	while (vault[i] && (vault[i] != '\n'))
		++i;
	if (vault[i] == '\n')
		++i;
	j = 0;
	while (vault[i])
		vault[j++] = vault[i++];
	while (vault[j])
		vault[j] = '\0';
	return (vault);
}
