/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:13:42 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/10 15:06:27 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	while (i < n)
	{
		*(dest + i) = *(source + i);
		i++;
	}
	return (dst);
}
