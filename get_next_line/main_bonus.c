/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:00:56 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/10 13:40:46 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	if (argc == 4)
	{
		i = 0;
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		while (i++ < 10)
		{
			line = get_next_line(fd1);
			printf("%s", line);
			free(line);
			line = get_next_line(fd2);
			printf("%s", line);
			free(line);
			line = get_next_line(fd3);
			printf("%s", line);
			free(line);
		}
	}
}
