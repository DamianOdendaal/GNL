/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:15 by dodendaa          #+#    #+#             */
/*   Updated: 2019/08/23 09:33:22 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*ft_join(char *line, char *buff)
{
	char *str;

	str = ft_strjoin(line, buff);
	ft_strdel(&line);
	return (str);
}

int		buff_read(int fd, char **stat)
{
	char	buff[BUFF_SIZE + 1];
	int		res;

	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (*stat == NULL)
			*stat = ft_strdup(buff);
		else
			*stat = ft_join(*stat, buff);
		if (ft_strchr(*stat, '\n'))
			break ;
	}
	return (res);
}


int		ft_output(char **hold, char **line)
{ 
	char *temp;
	char *newl;
	int i;

	i = 0;
	newl = ft_strchr(*hold, '\n');
	if (newl != NULL)
	{
		*newl = '\0';
		*line = ft_strdup(*hold);
		printf("%s\n", *hold);
		temp = ft_strdup(ft_strchr(*hold, '\0'));
		ft_strdel(hold);
		
		*hold = temp;
		
	}
	else
	{
		*line = ft_strdup(*hold);
		ft_strdel(hold);
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
