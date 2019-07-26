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

char	*line_joiner(char *str, char **line)/* creating a helper function that will join what was read till newl to line then free line*/
{
		char *s;
		s = ft_strjoin(*line,str);
		free(line);
		return(s);
}

int		buff_read(char **line, char *buff)/* helper function that will help me read from the buffer */

	/* after reading from the buffer we need to store the information somewhere*/

void	info_move(); // first learn how to move information that you have read !!

int		get_next_line(const int fd, char **line)
{
	if (fd < 0 || read(fd, NULL, 0) || !line)
		return(-1);
	/*read from the buffer here */
	then do error check for buffer read here 

}
