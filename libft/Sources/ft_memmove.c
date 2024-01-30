/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:01:52 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 16:41:39 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t	n)
{
	char		*pdest;
	char		*ldest;
	const char	*psrc;
	const char	*lsrc;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	if (pdest < psrc)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		lsrc = psrc + (n - 1);
		ldest = pdest + (n - 1);
		while (n--)
			*ldest-- = *lsrc--;
	}
	return (dest);
}
