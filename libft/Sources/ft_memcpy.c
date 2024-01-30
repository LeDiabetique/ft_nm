/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:56:48 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 13:11:41 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	n)
{
	char		*pdest;
	const char	*psrc;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
		n--;
	}
	return (dest);
}
/*
int main()
{
	char des [50] = "ugooooooo";
	char sr [50] = "Lagf";

	printf("%s",ft_memcpy(des, sr, 10));

	return (0);
}*/
