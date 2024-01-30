/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:48:15 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/10 10:36:23 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t count)
{
	char	*p;

	p = (char *)str;
	while (count--)
	{
		*(p++) = (char)c;
	}
	return (str);
}
/*int main()
{
	char str[50] = "HugoDIOT";
	int d;
	d = 's';

	printf("%s", ft_memset(str,d,4));
}*/
