/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:36:24 by dodendaa          #+#    #+#             */
/*   Updated: 2019/07/26 14:41:17 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 7
# define MFD 1025
# include "libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>

int		get_next_line(const int fd, char **line);

#endif
