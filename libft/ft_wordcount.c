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

size_t		ft_wordcount(char *str, char delim)
{
	size_t i;
	size_t wordc;

	i = 0;
	wordc = 0;
	while (str[i])
	{
		while (str[i] == delim && str[i])
			i++;
		while (str[i] != delim && str[i])
			i++;
		if (str[i] == str[i])
			wordc++;
	}
	return (wordc);
}
