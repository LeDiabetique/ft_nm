/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:39:58 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 09:51:18 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((*ps1 || *ps2) && (*ps1 == *ps2))
	{
		if (n == 1)
			return (0);
		ps1++;
		ps2++;
		n--;
	}
	return (*(unsigned char *)ps1 - *(unsigned char *)ps2);
}
