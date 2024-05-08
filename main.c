/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:47:17 by passunca          #+#    #+#             */
/*   Updated: 2023/11/25 19:01:24 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
# include "lib/libft/libft/libft.h"			// libft library
# include "lib/libft/ft_printf/ft_printf.h" 	// ft_printf
#include "srcb/get_next_line.h"
#include "srcll/get_next_line.h"

int main()
{
	int n = 1;
	char *str = NULL;
	// int fd = open("srcb/get_next_line.h", O_RDONLY);
	// int fd = open("files/mini-vulf.txt", O_RDONLY);
	int fd = open("files/vulf.txt", O_RDONLY);
	// int fd = open("files/read_error.txt", O_RDONLY);

	ft_printf("Testing get_next_line\n\n");
	
	while ((str = get_next_line(fd)) != NULL)
	{
		ft_printf("%d:\t%s", n, str);
		free(str);
		++n;
	}
	close(fd);
	return (0);
}
