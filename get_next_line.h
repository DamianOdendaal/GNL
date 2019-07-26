/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:36:24 by event             #+#    #+#             */
/*   Updated: 2019/07/26 14:41:17 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>

char	*line_joiner(char *str, char **line);
int		buff_read(char **line, char * buff);
void	info_move()
int		get_next_line(const int fd, char **line);

#endif
