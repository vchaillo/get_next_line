/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:31:21 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/09 00:38:12 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
	{
		while (get_next_line(0, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			close(fd);
			return (0);
		}
		while (get_next_line(fd, &line) == 1) 
		{
			ft_putendl(line);
			free(line);
		}
	}
	return (0);
}
