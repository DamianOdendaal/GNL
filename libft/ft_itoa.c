/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:41:11 by dodendaa          #+#    #+#             */
/*   Updated: 2019/06/24 10:44:48 by dodendaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*strr;
	int		intlen;

	intlen = ft_intlen((size_t)n);
	if (!(strr = ft_strnew(intlen)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		strr[0] = '-';
		strr[1] = '\0';
		strr = ft_strjoin(strr, ft_itoa(-n));
	}
	else if (n >= 10)
		strr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else
	{
		strr[0] = (n + '0');
		strr[1] = '\0';
	}
	return (strr);
}
