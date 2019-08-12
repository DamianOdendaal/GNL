/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:51:04 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 10:43:28 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	strtp;
	size_t	wordc;

	i = 0;
	wordc = i;
	if (!s)
		return (NULL);
	if (!(array = (char **)ft_memalloc(sizeof(char *) *\
					(ft_wordcount((char *)s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		strtp = i;
		while ((s[i] != c) && (s[i]))
			i++;
		if (i > strtp)
			array[wordc++] = ft_strsub(s, strtp, (i - strtp));
	}
	array[wordc] = 0;
	return (array);
}
