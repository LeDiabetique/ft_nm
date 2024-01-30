/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:44:51 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 15:57:11 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t i)
{
	size_t	n;
	size_t	swap;

	n = 0;
	if ((dest == NULL || src == NULL) && i == 0)
		return (0);
	swap = ft_strlen(dest);
	if (dest == NULL && src == NULL)
		return (0);
	if (i <= swap)
		return (i + ft_strlen(src));
	while (src[n] != '\0' && swap + 1 < i)
	{
		dest[swap] = src[n];
		n++;
		swap++;
	}
	dest[swap] = '\0';
	return (swap + ft_strlen(&src[n]));
}
