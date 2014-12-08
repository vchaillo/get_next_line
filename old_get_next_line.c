/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:14:44 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/09 00:36:25 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		my_realloc(int const fd, char **buffer, int *ret)
{
	char			*tmp;

	tmp = ft_strnew(BUFF_SIZE + 1);
	if ((*ret = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	tmp[*ret] = '\0';
	*buffer = ft_strjoin(*buffer, tmp);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buffer = "\0"; /*     *buffer[255] = '\0'      */
	char			*str;
	int				ret;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (*buffer == '\0')
		buffer = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buffer, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(buffer);
			ft_memmove(buffer, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		else 
			*line = ft_strdup(buffer);
		if (my_realloc(fd, &buffer, &ret) == -1)
			return (-1);
		if (ret == 0)
			return (0);
	}
	return (0);
}
