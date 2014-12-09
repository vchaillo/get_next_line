/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:31:21 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/09 01:53:45 by vchaillo         ###   ########.fr       */
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
			ft_putendl("Veuillez entrer un nom de fichier valide");
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
