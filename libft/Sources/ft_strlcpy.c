/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:53:28 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 15:42:34 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t i)
{
	size_t	n;

	n = 0;
	if (i > 0)
	{
		while (src[n] != '\0' && n < i - 1)
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	while (src[n])
		n++;
	return (n);
}
