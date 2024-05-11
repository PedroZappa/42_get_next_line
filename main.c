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

// Test mandatory
// int main(int argc, char **argv)
// {
// 	int n = 1;
// 	char *input_list = NULL;
// 	int fd;
//
// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
//
// 	ft_printf("Testing get_next_line\n\n");
// 	while ((input_list = get_next_line(fd)) != NULL)
// 	{
// 		ft_printf("%d:\t%s", n, input_list);
// 		free(input_list);
// 		++n;
// 	}
// 	close(fd);
// 	return (0);
// }

// Test bonus
int main(int argc, char **argv)
{
    char *input_list = NULL;
    int fd[FOPEN_MAX];
    int num_fds = (argc - 1);
    int n;
    int i;

    if (argc < 2)
	{
		ft_printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
	}
	// open fds
	for (i = 0; i < num_fds; ++i) 
	{
		if ((fd[i] = open(argv[i + 1], O_RDONLY)) == -1)
		{
			ft_printf("Error opening file: %s\n", argv[i + 1]);
			return 1;
		}
	}
	// test get_next_line
    ft_printf("Testing get_next_line\n\n");
	n = 1;
    for (i = 0; i < num_fds; ++i) {
        while ((input_list = get_next_line(fd[i]))!= NULL) {
            ft_printf("%d:\t%s", n, input_list);
            free(input_list);
            ++n;
        }
    }
	// close fds
	for (int i = 0; i < num_fds; ++i) {
		close(fd[i]);
	}
    return 0;
}
