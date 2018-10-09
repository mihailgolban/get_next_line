/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:23:32 by mihail            #+#    #+#             */
/*   Updated: 2016/11/28 14:16:37 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_cpbuff(char **from, char **to)
{
	char *ptrn;
	char *tofree;

	ptrn = ft_strchr(*from, '\n');
	if (ptrn)
		*ptrn = '\0';
	tofree = *to;
	if (!(*to = ft_strjoin(tofree, *from)))
		return (-1);
	free(tofree);
	if (ptrn)
	{
		*from = ft_strcpy(*from, ptrn + 1);
		return (1);
	}
	*from[0] = '\0';
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buf[MAX_FD];
	int			r;
	int			flag;

	flag = 0;
	if (line == NULL || fd < 0 || fd > MAX_FD ||
			(!buf[fd] && (buf[fd] = ft_strnew(BUFF_SIZE)) == NULL))
		return (-1);
	*line = ft_strnew(0);
	while (buf[fd][0] != '\0')
	{
		if ((flag = ft_cpbuff(&buf[fd], line)) != 0)
			return (flag);
	}
	while ((r = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		buf[fd][r] = '\0';
		if ((flag = ft_cpbuff(&buf[fd], line)) != 0)
			return (flag);
		if (r != BUFF_SIZE)
			return (1);
	}
	if (*line[0] != '\0')
		return (1);
	return (r);
}
