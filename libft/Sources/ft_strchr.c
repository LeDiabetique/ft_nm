/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:04:45 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 08:41:59 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*str, int c)
{
	char	i;

	i = c;
	if (i == '\0')
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (0);
}
/*
int main ()
{
	char *string = "this is My string";
	printf("%s", ft_strchr(string,'M')); 
}*/
