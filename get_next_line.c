/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:38:45 by event             #+#    #+#             */
/*   Updated: 2019/07/26 14:41:11 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		buff_read(char **line, char *buff)
{
	int i;
	int start;

	i = 0;
	start = 0;
	while(buff[i] != '\n' || buff[i] != '\0')
		i++;
	if(buff[i] == '\n')// if we find the \n char make the
	{
		line = ft_strsub(buff, start, i);
	}
		
}
	/* after reading from the buffer we need to store the information somewhere*/

void	info_move(); // first learn how to move information that you have read !!

int		get_next_line(const int fd, char **line)
{
	static char *stat[1024];// crart
	char *buff;

	if (fd < 0 || read(fd, NULL, 0) || !line)
		return(-1);
	/*read from the buffer here */
	then do error check for buffer read here 

}
