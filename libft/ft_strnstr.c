/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:15:50 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/14 16:15:08 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && (&haystack[i] + ft_strlen(needle)) \
			<= (haystack + len))
	{
		if (haystack[i] == needle[0] && \
				(ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
