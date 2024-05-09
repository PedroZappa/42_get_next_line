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

#include <fcntl.h>
# include "lib/libft/libft/libft.h"			// libft library
# include "lib/libft/ft_printf/ft_printf.h" 	// ft_printf
#include "srcb/get_next_line.h"
#include "srcll/get_next_line.h"

int main(int argc, char **argv)
{
	int n = 1;
	char *str = NULL;
	int fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);

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
