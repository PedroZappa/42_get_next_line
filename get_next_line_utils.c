/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:00:52 by passunca          #+#    #+#             */
/*   Updated: 2023/11/13 11:08:58 by passunca         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "get_next_line.h"

/* checks for a '\n' character in the 'strs' list*/
int	ft_isnewline(t_list *strs)
{
	int		i;
	t_list	*curr_strs;

	if (!strs)
		return (0);
	curr_strs = ft_getlastnode(strs);
	i = 0;
	while (curr_strs->str[i])
	{
		if (curr_strs->str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

/* Returns pointer to last node in 'strs' list */
t_list	*ft_getlastnode(t_list *strs)
{
	while (strs && strs->next)
		strs = strs->next;
	return (strs);
}

/* Computes number of chars in current line (incl. '\n') and allocs memory */
void	ft_makeline(char **line, t_list *strs)
{
	int	seglen;
	int	linelen;

	linelen = 0;
	while (strs)
	{
		seglen = 0;
		while (strs->str[seglen])
		{
			if (strs->str[seglen] == '\n')
			{
				++linelen;
				break ;
			}
			++linelen;
			++seglen;
		}
		strs = strs->next;
	}
	*line = malloc(sizeof(char) * (linelen + 1));
	if (!*line)
		return ;
}

/* Free the entire 'strs' list */
void	ft_freelst(t_list *strs)
{
	t_list	*curr_str;
	t_list	*next_str;

	curr_str = strs;
	while (curr_str)
	{
		free(curr_str->str);
		next_str = curr_str->next;
		free(curr_str);
		curr_str = next_str;
	}
}

/* Get the length of a givengiven 'str' */
int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str++)
		++len;
	return (len);
}
