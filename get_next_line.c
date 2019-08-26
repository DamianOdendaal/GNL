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
		temp = ft_strdup(ft_strchr(*hold, '\0') + 1);
		free(*hold);
		if (temp)
		{
			*hold = ft_strdup(temp);
			free(temp);
		}
	}
	else
	{
		*line = ft_strdup(*hold);
		ft_memdel((void **)hold);
	}
	return (1);
}

int		free_return(char **buff,  int ret)
{
	free(*buff);
	buff = NULL;
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char *stat[MFD];
	int			ret;

	if (fd < 0 || fd > MFD || read(fd, stat[fd], 0) < 0 || !line)
		return (free_return(&stat[fd], -1));
	if (!(stat[fd]))
		stat[fd] = ft_strnew(0);
	ret = buff_read(fd, &stat[fd]);
	if (ret < 0)
		return (free_return(&stat[fd], -1));
	if (ft_strlen(stat[fd]) == 0)
		return (0);
	return (ft_output(&stat[fd], line));
}
