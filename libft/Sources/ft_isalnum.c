/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:08:37 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/10 10:31:36 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*int main()
{
	int b;
	int d;
	int a;

	b = 50;
	d = 66;
	a = 109;

	printf("%d\n", ft_isalnum(b));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", ft_isalnum(a));
}*/
