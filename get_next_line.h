/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:38 by passunca          #+#    #+#             */
/*   Updated: 2023/11/15 12:19:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

// Default compile time buffersize
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

// Get next line functions
char	*ft_getline(int fd, char *input, char *line);
char	*ft_gettillnl(char *input);
char	*ft_getrest(char *input);

// Utils functions
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);

#endif
