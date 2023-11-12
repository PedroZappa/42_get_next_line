/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:10:04 by passunca          #+#    #+#             */
/*   Updated: 2023/11/12 11:06:14 by passunca         ###   ########.fr       */
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

// Node buffer to store read strs
typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

// Get next line functions
char	*get_next_line(int fd);
void	ft_getline(int fd, t_list **strs, int *c_read);
void	ft_storestr(t_list **strs, char *buffer, int c_read);
void	ft_getstrs(t_list *strs, char **line);
void	ft_clear_strs(t_list **strs);

// Utils functions
int		ft_isnewline(t_list *strs);
t_list	*ft_getlastnode(t_list *strs);
void	ft_makeline(char **line, t_list *strs);
void	ft_freelst(t_list *strs);
int		ft_strlen(const char *str);

#endif
