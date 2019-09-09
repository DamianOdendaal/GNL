/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:15 by dodendaa          #+#    #+#             */
/*   Updated: 2019/09/09 13:42:17 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		buff_read(int fd, char **stat)
{
	char	*store;
	int		read_bytes;
	char	buff[BUFF_SIZE + 1];

	while (ft_strchr(*stat, '\n') == NULL)
	{
		read_bytes = read(fd, buff, BUFF_SIZE);
		buff[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		store = ft_strjoin(*stat, buff);
		free(*stat);
		*stat = ft_strdup(store);
		free(store);
	}
	return (1);
}

int		ft_output(char **hold, char **line)
{
	char *temp;
	char *newl;

	newl = ft_strchr(*hold, '\n');
	if (newl != NULL)
	{
		*newl = '\0';
		*line = ft_strdup(*hold);
		temp = ft_strdup(newl + 1);
		ft_strdel(hold);
		if (temp)
			*hold = temp;
	}
	else
	{
		*line = *hold;
		*hold = NULL;
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *stat[MFD];
	int			ret;

	if (fd < 0 || fd > MFD || read(fd, stat[fd], 0) < 0 || !line)
		return (-1);
	if (!(stat[fd]))
		stat[fd] = ft_strnew(0);
	ret = buff_read(fd, &stat[fd]);
	if (ret < 0)
		return (-1);
	if (ft_strlen(stat[fd]) == 0)
		return (0);
	return (ft_output(&stat[fd], line));
}
