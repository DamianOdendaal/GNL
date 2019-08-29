/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:58:16 by dodendaa          #+#    #+#             */
/*   Updated: 2019/08/29 11:46:25 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordcount(const char *s, char c)
{
	size_t	index;
	size_t	wordcount;

	index = 0;
	wordcount = 0;
	if (s != NULL)
	{
		while (s[index])
		{
			while ((s[index] == c) && (s[index] != '\0'))
				index++;
			if ((s[index] != c) && (s[index] != '\0'))
				wordcount++;
			while ((s[index] != c) && (s[index] != '\0'))
				index++;
		}
		return (wordcount);
	}
	return ((size_t)NULL);
}

