/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:27:49 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/22 08:29:05 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
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

static char	*ft_itoa(int n)
{
	int		len;
	long	i;
	char	*str;

	i = n;
	len = ft_digitnb(i);
	str = (char *)malloc(sizeof(*str) * (len + 1));
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
}*/

int	ft_printnbr(int n)
{
	char	*str;
	int		p;

	p = 0;
	str = ft_itoa(n);
	p = ft_putstr(str);
	free(str);
	return (p);
}
