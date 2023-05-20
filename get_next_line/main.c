/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:00:56 by rnovotny          #+#    #+#             */
/*   Updated: 2023/03/07 19:14:09 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	while (i++ < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
}
