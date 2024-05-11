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
//
// static int	ft_argv_count(char *argv);
// static void ft_exit(char **argv, int n);
//
// int main(int argc, char **argv)
// {
// 	char	**input_list;
// 	char	*line;
//     int		fds[FOPEN_MAX];
//     int		n_files;
//     int		n = 1;
// 	int		i;
//
//     if (argc < 2)
// 		ft_exit(argv, 1);
// 	input_list = ft_split(argv[1], ' ');
// 	argc = ft_argv_count(*input_list) + 1;
// 	n_files = (argc - 1);
//
//     ft_printf("Testing get_next_line\n\n");
// 	i = 0;
// 	while ((i < n_files) && )
// 	{
// 		while ((line = get_next_line(fds[i])) != NULL)
// 		{
// 			ft_printf("%d:\t%s", n, input_list[i]);
// 			free(input_list[i]);
// 			++i;
// 		}
// 	}
//
//     // Close all fds & input_list
// 	for (i = 0; i < n_files; ++i)
// 		close(fds[i]);
// 	for (i = 0; i < n_files; ++i)
// 		free(input_list[i]);
// 	free(input_list);
//
//     return 0;
// }
//
// static int	ft_argv_count(char *argv)
// {
// 	int	n;
//
// 	n = 0;
// 	while (argv[n])
// 		++n;
// 	return (n);
// }
//
// static void ft_exit(char **argv, int n)
// {
// 	printf("Usage: %s <file1> <file2>...\n", argv[0]);
// 	exit(n);
// }
//
//

int main(int argc, char **argv)
{
    int n = 1;
    char *input_list = NULL;
    int fd[2]; // Example array of two file descriptors
    int num_fds = sizeof(fd) / sizeof(fd[0]); // Number of file descriptors

    if (argc!= 3) // Adjusted to accept two arguments for two file descriptors
        return 0;

    // Open the file descriptors
    fd[0] = open(argv[1], O_RDONLY);
    fd[1] = open(argv[2], O_RDONLY);

    if (fd[0] == -1 || fd[1] == -1) {
        perror("Error opening file");
        return 1;
    }

    ft_printf("Testing get_next_line\n\n");
    for (int i = 0; i < num_fds; ++i) {
        while ((input_list = get_next_line(fd[i]))!= NULL) {
            ft_printf("%d:\t%s", n, input_list);
            free(input_list);
            ++n;
        }
    }

    close(fd[0]);
    close(fd[1]);
    return 0;
}
