/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:14:44 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/09 01:09:32 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* buffer sert a faire la lecture
 * tmp sert a copier le reste de la ligne contenue buffer apres le '\n'
 * line est la variable a completer avant de retourner 1*/

static int		ft_read(const int fd, char **tmp, char **buffer, int *ret)
{
	/* La fonction effectue une lecture avec le buffer, puis elle l'ajoute 
	 * dans le tmp au cas ou il y aurait un reste d'apres '\n'
	 * La fonction renvoie 1 en cas de lecture reussie sinon -1*/

	*buffer = ft_strnew(BUFF_SIZE + 1);
	if ((*ret == read(fd, *buffer, BUFF_SIZE)) == -1)
		return (-1);
	*buffer[*ret] = '\0';
	*tmp = ft_strjoin(*tmp, *buffer);
	return (1);
}

static int		ft_addline(char **tmp, char **buffer, int *ret)
{
	/* La fonction renvoie 1 si elle trouve une ligne sinon elle renvoie 0
	 * La fonction recherche un '\n'
	 * - Si il y en a un:
	 *   - Copie du buffer jusqu'au '\n' dans tmp
	 *   - On positionne le pointeur buffer sur le char apres le '\n'
	 * - Si il n'y en a pas:
	 *   - On verifie si le ret < BUFF_SIZE, on ajoute buffer dans line 
	 *   - Si ce n'est pas le cas on copie buffer dans tmp et on 
	 *   relance la lecture car nous n'avons pas encore une ligne complete */

	char	*str;

	if ((str = ft_strchr(*buffer, '\n')) != NULL)
	{
		*str = '\0';
		*tmp = ft_strjoin(*tmp, *buffer);
		*buffer = str + 1;
		return (0);
	}
	if (*ret < BUFF_SIZE && *buffer == '\0')
	{
		*tmp = ft_strjoin(*tmp, *buffer);
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	/* Normalement une fois le fichier lu, si le buffer est en static char,
	 * le ret = 0 des la premiere lecture. Voila le seul cas ou la fontion
	 * doit retourner 0 */

	static char		*buffer;
	char			*tmp;
	int				ret;
	int				test;

	test = 0;
	if (!line || fd < 0)
		return (-1);
	ret = 1;
	tmp = ft_strnew(0);
	while (ret > 0)
	{
			while ((test = ft_addline(&tmp, &buffer, &ret)) == 1)
			{
				if ((ft_read(fd, &tmp, &buffer, &ret)) == -1)
					return (-1);
				ft_putnbr(test);
//				ft_putendl(buffer);
			}
			*line = ft_strdup(tmp);
//			ft_putendl(*line);
//			ft_putendl(tmp);
			return (1);
	}
	return (0);
}
