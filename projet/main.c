/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:31:21 by vchaillo          #+#    #+#             */
/*   Updated: 2015/01/08 21:26:40 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line = NULL;

	if (argc == 1)
	{
		while (get_next_line(0, &line) == 1)
			ft_putendl(line);
	}
	else if (argc == 3)
	{
		if ((fd1 = open(argv[1], O_RDONLY)) == -1)
		{
			close(fd1);
			ft_putstr("Failed to open ");
			ft_putstr(argv[1]);
			ft_putendl(" file");
			return (0);
		}
		if ((fd2 = open(argv[2], O_RDONLY)) == -1)
		{
			close(fd2);
			ft_putstr("Failed to open ");
			ft_putstr(argv[2]);
			ft_putendl(" file");
			return (0);
		}
		else
		{
			if (get_next_line(fd1, &line) == 1)
				ft_putendl(line);
			if (get_next_line(fd2, &line) == 1)
				ft_putendl(line);
			if (get_next_line(fd1, &line) == 1)
				ft_putendl(line);
			if (get_next_line(fd2, &line) == 1)
				ft_putendl(line);
		}
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			close(fd);
			ft_putstr("Failed to open ");
			ft_putstr(argv[1]);
			ft_putendl(" file");
			return (0);
		}
		else
		{
			while (get_next_line(fd, &line) == 1)
				ft_putendl(line);
		}
	
	}
	return (0);
}
