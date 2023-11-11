/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:00:52 by passunca          #+#    #+#             */
/*   Updated: 2023/11/11 23:23:07 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_isnewline(t_list *strs)
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

t_list *ft_getlastnode(t_list *strs)
{
	while (strs && strs->next)
		strs = strs->next;
	return (strs);
}
