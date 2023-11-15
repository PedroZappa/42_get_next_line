/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:47:17 by passunca          #+#    #+#             */
/*   Updated: 2023/11/15 13:04:49 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int n = 1;
	char *str = NULL;
	// int fd = open("files/vulf.txt", O_RDONLY);
	// int fd = open("get_next_line.h", O_RDONLY);
	int fd = open("files/mini-vulf.txt", O_RDONLY);
	// int fd = open("files/read_error.txt", O_RDONLY);

	str = get_next_line(fd);
	// int i = 0;
	while (str)
	{
		printf("Line\t%d:\t%s", n, str);
		free(str);
		// if(i == 0)
		// {
		// 	close(fd);
		// 	i++;
		// }
		str = get_next_line(fd);
		// printf("fd : %d", fd);
		// if(i == 1)
		// {
		// 	fd = open("files/mini-vulf.txt", O_RDONLY);
		// 	str = get_next_line(fd);
		// 	++i;
		// }
		++n;
	}
	free(str);
	return (0);
}
