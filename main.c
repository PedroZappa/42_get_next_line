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
// 	char *str = NULL;
// 	int fd;
//
// 	if (argc != 2)
// 		return (0);
// 	fd = open(argv[1], O_RDONLY);
//
// 	ft_printf("Testing get_next_line\n\n");
// 	while ((str = get_next_line(fd)) != NULL)
// 	{
// 		ft_printf("%d:\t%s", n, str);
// 		free(str);
// 		++n;
// 	}
// 	close(fd);
// 	return (0);
// }

// Test bonus
int main(int argc, char **argv)
{
    int n = 1;
    char *str = NULL;
    int *fds;
    int num_files;

    if (argc < 2)
    {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    num_files = argc - 1;
	    fds = malloc(num_files * sizeof(int));

    for (int i = 0; i < num_files; i++)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        if (fds[i] == -1)
        {
            printf("Error opening file: %s\n", argv[i + 1]);
            return 1;
        }
    }

    ft_printf("Testing get_next_line\n\n");
    while (1)
    {
        int any_line_read = 0;
        for (int i = 0; i < num_files; i++)
        {
            str = get_next_line(fds[i]);
            if (str != NULL)
            {
                ft_printf("%d:\t%s", n, str);
                free(str);
                any_line_read = 1;
            }
        }
        if (!any_line_read)
            break;
        n++;
    }

    for (int i = 0; i < num_files; i++)
        close(fds[i]);
    free(fds);

    return 0;
}
