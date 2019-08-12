/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:45 by dodendaa          #+#    #+#             */
/*   Updated: 2019/08/01 16:17:58 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// insert new headers in your files 


#include "get_next_line.h"

char	*line_join(char *line, char *buff)
{
	char *str;

	str = ft_strjoin(line, buff);
	free(line);
	return(str);

}


int		line_reader(int fd, char **buff)
{
	int bytes_read;
	char temp[BUFF_SIZE + 1];

	while(bytes_read = read(fd, temp, BUFF_SIZE) > 0)
	{
		if(buff[fd] == NULL)
			buff[fd] = ft_strdup(buff);
		else
			buff[fd] = line_join(buff[fd] , temp);
 		if(ft_strchr(buff[fd], '\n'))
			break;
	}
	return(res);
}



/*int		buff_read(int fd, char **buff)
{
	int		bytes_read;
	char	*store;
	char	temp[BUFF_SIZE + 1];
	while(!(ft_strchr(*buff, '\n')))
	{
		if (!(*buff))
			*buff = ft_strnew(0);
		bytes_read = read(fd, temp, BUFF_SIZE);
		if (bytes_read < 0)
			return (0);
		temp[bytes_read] = '\0';
		store = ft_strjoin(*buff, temp);
		free(*buff);
		*buff = store;
	}
	return(1);
}*/

char	*ft_output(char **buff)
{
	char	*line;
	char	*newl;
	char	*hold;

	newl = ft_strchr(*buff, '\n');
	if (newl)
	{
		*newl = '\0';
		line = ft_strdup(*buff);
		hold = ft_strdup(*buff + 1);
		free(*buff);
		*buff = hold;
	}
	else
	{
		line = ft_strdup(*buff);
		free(*buff);
	}
	return(line);

}

int		get_next_line(const int fd, char **line)
{
	static char *stat[4096];
	int			res;
	if (fd < 0 || read(fd, NULL, 0) || !line || fd > MFD)
		return(-1);	
	res = line_reader(fd, line)
	if(res < 0)
		return(-1);
	if(ft_strlen(stat[fd]) == 0)
		return(0);
	*line = ft_output(&stat[fd]);
	return(1);
}
