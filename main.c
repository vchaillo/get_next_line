/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:31:21 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/10 22:25:10 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int	fd;
	char	*line = NULL;

	if (argc == 1)
	{
		while (get_next_line(0, &line) == 1)
		{
			ft_putendl(line);
		}
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			close(fd);
			ft_putendl("failed to open the file");
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
