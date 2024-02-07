/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:25:40 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 10:53:29 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*s, int c, size_t n)
{
	unsigned const char	*ps;

	ps = (unsigned const char *)s;
	while (n)
	{
		if (*ps == (unsigned char)c)
			return ((unsigned char *)ps);
		ps++;
		n--;
	}
	return (NULL);
}
