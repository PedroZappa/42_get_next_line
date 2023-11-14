/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:47:17 by passunca          #+#    #+#             */
/*   Updated: 2023/11/14 16:10:05 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int n = 1;
	// int max_n = 290;
	char *str = NULL;
	// int fd = open("files/vulf.txt", O_RDONLY);
	// int fd = open("get_next_line.h", O_RDONLY);
	int fd = open("files/mini-vulf.txt", O_RDONLY);

	str = get_next_line(fd);

	while (str)
	{
		printf("Line\t%d:\t%s", n, str);
		free(str);
		close(fd);
		str = get_next_line(fd);
		// printf("fd : %d", fd);
		++n;
	}
	free(str);
	return (0);
}
