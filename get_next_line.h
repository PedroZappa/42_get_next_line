/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:23:38 by passunca          #+#    #+#             */
/*   Updated: 2023/11/15 11:17:40 by passunca         ###   ########.fr       */
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

// Utils functions
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);

#endif
