/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:38 by passunca          #+#    #+#             */
/*   Updated: 2023/11/21 15:16:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// Default compile time buffersize
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

// Utils functions
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);

#endif
