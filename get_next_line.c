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

	if (!(*buff))
	{
		*buff = ft_strnew(0);
	}

	bytes_read = read(fd, temp, BUFF_SIZE + 1);
	if (bytes_read <= 0)
	{
		return (0);
	}
	temp[bytes_read] = '\0';
	

	// int i;
	// int start;
	// int rd;

	// i = 0;
	// start = 0;
	// while(buff[i] != '\n' || buff[i] != '\0')
	// 	i++;
}
	/* after reading from the buffer we need to store the information somewhere*/

void	info_move();     // first learn how to move information that you have read !!

int		get_next_line(const int fd, char **line)
{
	static char *stat[4096];
	char *buff;

	if (fd < 0 || read(fd, NULL, 0) || !line)
		return(-1);
	buff = ft_strnew(BUFF_SIZE);
	if (!stat[fd])
		return(-1);
	
	/*read from the buffer here 
	then do error check for buffer read here*/



}
