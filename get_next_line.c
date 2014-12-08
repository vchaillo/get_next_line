/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 08:14:44 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/08 22:30:31 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* buffer sert a faire la lecture
 * tmp sert a copier le reste de la ligne contenue buffer apres le '\n'
 * line est la variable a completer avant de retourner 1*/

static void		ft_read()
{
	/*La fonction effectue une lecture avec le buffer, puis elle l'ajoute 
	 * dans le tmp au cas ou il y aurait un reste d'apres '\n'*/
}

static void		ft_addline()
{
	/*La fonction recherche un '\n'
	 * - Si il y en a un:
	 *   - Copie de tmp et buffer jusqu'au '\n' dans line
	 *   - On positionne le pointeur buffer sur le char apres le '\n'
	 * - Si il n'y en a pas:
	 *   - On verifie si le ret < BUFF_SIZE, on ajoute buffer dans line 
	 *   - Si ce n'est pas le cas on copie buffer dans tmp et on 
	 *   relance la lecture car nous n'avons pas encore une ligne complete */
}

int				get_next_line(int const fd, char **line)
{
	/* Normalement une fois le fichier lu, si le buffer est en static char,
	 * le ret 0 des la premiere lecture. Voila le seul cas ou la fontion
	 * doit retourner 0 */
	static char		*buffer = "\0";
	char			*tmp;
	int				ret;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (*buffer == '\0')
		buffer = ft_strnew(0);
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, BUFF_SIZE)) == -1)
			return (-1);
		if ((ret == 0 && tmp[0] == '\0')
			return (0);
		ft_addline(&tmp, &buffer, *line);
	}
	return (1);
}
