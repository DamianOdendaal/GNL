/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:06:10 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 09:23:19 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	size_t	len;

	a = (char)c;
	len = ft_strlen(s);
	if (s[len] == a)
		return ((char *)&s[len]);
	while (len)
	{
		if (s[len - 1] == a)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (NULL);
}
