/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:14:59 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 09:06:27 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	uc = (unsigned char)c;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		if (*(source + i) != uc)
		{
			*(dest + i) = *(source + i);
			i++;
		}
		else if (*(source + i) == uc)
		{
			*(dest + i) = *(source + i);
			return (dest + i + 1);
		}
	}
	return (NULL);
}
