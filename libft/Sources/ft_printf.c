/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:29:20 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/06 11:13:01 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_formats(va_list args, const char format)
{
	int	p_lenght;

	p_lenght = 0;
	if (format == 'c')
		p_lenght += ft_putchar(va_arg(args, int));
	else if (format == 's')
		p_lenght += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		p_lenght += ft_putptr(va_arg(args, unsigned long long));
	else if (format == 'i' || format == 'd')
		p_lenght += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		p_lenght += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		p_lenght += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		p_lenght += ft_printpercent();
	return (p_lenght);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_print_formats(args, str[i + 1]);
			i++;
		}
		else
			print += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
/*
#include <stdio.h>

int main()
{

	char *c = "hugo";
	char *b;

	b = c;
	ft_printf("%p\n", c);
	c = "hd";
	printf("%p\n", c);
	ft_printf("%p\n", b);
	printf("%p\n", b);
}*/
