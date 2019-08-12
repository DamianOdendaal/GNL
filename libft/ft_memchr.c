/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:15:20 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 10:58:14 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dup;
	unsigned char	a;

	i = 0;
	dup = (unsigned char *)s;
	a = (unsigned char)c;
	while (i < n)
	{
		if (*(dup + i) == a)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
