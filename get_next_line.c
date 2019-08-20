/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:15 by dodendaa          #+#    #+#             */
/*   Updated: 2019/08/20 10:17:18 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_join(char *line, char *buff)
// {
// 	char *str;

// 	str = ft_strjoin(line, buff);
// 	ft_strdel(&line);
//	return (str);

// }

//int		ft_str_reader(int fd, char **line)
//{
//	char	buff[BUFF_SIZE + 1];
//	int 	res;
//	
//	while ((res = read(fd, tmep, BUFF_SIZE)))
//	{
//		buff[ret] = '\0';
//		if (line[fd] == NULL)
//			line[fd] = ft_strdup(buff);
//		else
//			line[fd] = ft_join(*line, buff);
//		if (ft_strchr(line[fd], '\n'))
//			break;
//	}
//	return (res);
//}

// test code to see if my reading is wrong

int		buff_read(int fd, char **stat)
{
	char	temp[BUFF_SIZE + 1];
	char	*store;
	size_t	ret;

	if (*stat == NULL)
		*stat = ft_strnew(0);
	while ((ft_strchr(*stat, '\n') != NULL))
	{
		ret = read(fd, temp, BUFF_SIZE);
		if (ret < 0)
			return (0);
		temp[ret] = '\0';
		store = ft_strjoin(*stat, temp);
		ft_strdel(stat);
		*stat = ft_strdup(temp);
	}
	return (1);
}

int		ft_output(char **hold, char **line)
{
	char *temp;
	char *newl;

	newl = ft_strchr(*hold, '\n');
	// try a while loop that would get you to the newl char and or to the null terminator
	if (newl)
	{
		*newl = '\0';
		*line = ft_strdup(*hold);
		temp = ft_strdup(newl + 1);
		ft_strdel(hold);
		if (temp)
		{
			*hold = ft_strdup(temp);
			ft_strdel(&temp);
		}
		if ((*line)[0] == '\0')
			ft_strdel(line);  // just for testing purposes
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

	if (fd < 0 || fd > MFD || read(fd, stat[fd] , 0) < 0 || !line)
		return (-1);
	ret = buff_read(fd, &stat[fd]);
	if (ret < 0)
		return (-1);
	if (ft_strlen(stat[fd]) == 0)
		return (0);
	return (ft_output(&stat[fd], line));
}
