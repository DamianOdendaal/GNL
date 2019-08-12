/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:16:12 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 13:32:35 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *a;

	if (!(a = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(a, '\0', size + 1);
	return (a);
}
