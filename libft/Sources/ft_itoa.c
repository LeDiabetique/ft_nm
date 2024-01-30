/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:04:01 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/16 08:12:27 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitnb(long n)

{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	long	i;
	char	*str;

	i = n;
	len = ft_digitnb(i);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (i == 0)
		str[0] = 48;
	if (i < 0)
	{
		str[0] = '-';
		i = -i;
	}
	while (i > 0)
	{
		str[len--] = 48 + (i % 10);
		i = i / 10;
	}
	return (str);
}
