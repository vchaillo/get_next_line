/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:14:44 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/09 14:00:14 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static int	my_realloc(int const fd, char **buffer, char *tmp, int *ret)
{
	if ((*ret = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	tmp[*ret] = '\0';
	*buffer = ft_strjoin(*buffer, tmp);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buffer = "\0";
	char			*str;
	char			*tmp;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	ret = BUFF_SIZE;
	tmp = ft_strnew(BUFF_SIZE + 1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buffer, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(buffer);
			ft_memmove(buffer, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		else if (ret < BUFF_SIZE)
		{
			*line = ft_strdup(buffer);
			return (1);
		}
		if (my_realloc(fd, &buffer, tmp, &ret) == -1)
			return (-1);
	}
	return (0);
}
