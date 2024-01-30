/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:20:40 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/22 15:05:01 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptrlen(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_printptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_printptr(num / 16);
		ft_printptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len += ft_putstr("0x0");
	else
	{
		len += write(1, "0x", 2);
		len += ft_ptrlen(num);
		ft_printptr(num);
	}
	return (len);
}
