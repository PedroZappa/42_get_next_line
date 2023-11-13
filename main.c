/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:47:17 by passunca          #+#    #+#             */
/*   Updated: 2023/11/13 15:41:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int n = 1;
	int max_n = 10;
	char *str = NULL;
	int fd = open("files/vulf.txt", O_RDONLY);

	while (n <= max_n)
	{
		str = get_next_line(fd);
		printf("Line\t%d:\t%s", n, str);
		// printf("fd : %d", fd);
		++n;
		free(str);
	}
	return (0);
}
