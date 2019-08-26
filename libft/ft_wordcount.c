/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:58:16 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 13:48:05 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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


int main (int ac, char **av)
{
	size_t num;
	if(ac == 2)
		num = ft_wordcount(av[1], ' ');
	printf("%lu\n", num);
	return (0);
}
