/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:14:44 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/11 19:01:03 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	my_realloc(int const fd, char **buffer, int *ret)
{
	char			*tmp;

	tmp = ft_strnew(BUFF_SIZE + 1);
	if ((*ret = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	if (*buffer == '\0')
		*buffer = ft_strnew(0);
	tmp[*ret] = '\0';
	*buffer = ft_strjoin(*buffer, tmp);
	return (0);
}

static int	get_endl(char **buffer, char **line)
{
	char			*str;

	if ((str = ft_strchr(*buffer, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(*buffer);
		ft_memmove(*buffer, str + 1, ft_strlen(str + 1) + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*buffer[256];
	int				ret;

	if (!line || fd < 0)
		return (-1);
	if (*line)
		free(*line);
	ret = BUFF_SIZE;
	while (ret > 0 || ft_strlen(buffer[fd]))
	{
		if ((get_endl(&buffer[fd], line)) == 1)
			return (1);
		if (my_realloc(fd, &buffer[fd], &ret) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(buffer[fd]))
		{
			*line = ft_strdup(buffer[fd]);
			free(buffer[fd]);
			return (1);
		}
	}
	return (0);
}
