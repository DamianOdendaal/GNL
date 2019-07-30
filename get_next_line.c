/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:45 by event             #+#    #+#             */
/*   Updated: 2019/07/29 16:56:36 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		buff_read(int fd, char **buff)
{
	int		bytes_read;
	char	*store;
	char	temp[BUFF_SIZE + 1];
	while(*buff != '\n')
	{
		if (!(*buff))
			*buff = ft_strnew(0);
		bytes_read = read(fd, temp, BUFF_SIZE);
		if (bytes_read <= 0)
			return (0);
		temp[bytes_read] = '\0';
		store = ft_strjoin(*buff, temp);
		free(buff);

	}

int		get_next_line(const int fd, char **line)
{
	static char *stat[4096];
	char *buff;

	if (fd < 0 || read(fd, NULL, 0) || !line)
		return(-1);
	buff = ft_strnew(BUFF_SIZE);
	
	/*read from the buffer here 
	then do error check for buffer read here*/



}
