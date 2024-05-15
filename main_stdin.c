/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:08:09 by passunca          #+#    #+#             */
/*   Updated: 2024/05/15 15:31:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "srcb/get_next_line.h"
# include <stdio.h>

int main(void)
{
	char	*line;
	int		fd;

	fd = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	return (0);
}
