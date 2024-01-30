/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:29:30 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/05 12:44:58 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_undigitnb(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_unitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_undigitnb(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_printunsigned(unsigned int n)
{
	char	*str;
	int		p;

	p = 0;
	if (n == 0)
		p += write(1, "0", 1);
	else
	{
		str = ft_unitoa(n);
		p += ft_putstr(str);
		free(str);
	}
	return (p);
}
