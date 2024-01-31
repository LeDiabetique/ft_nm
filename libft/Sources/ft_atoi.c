/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:51 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/10 10:30:59 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char	*str)
{
	char	*s;
	int		sign;
	int		res;

	s = (char *)str;
	sign = 1;
	res = 0;
	while (*s == 32 || *s == '\f' || *s == '\n'
		|| *s == '\r' || *s == '\t' || *s == '\v')
		s++;
	if (*s == '-')
	{
		sign = sign * -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		if (!(*s >= '0' && *s <= '9'))
			return (res * sign);
		s++;
	}
	return (res * sign);
}
/*int main () 
{
   int val;
   int vala;
   char str[20];
   
   strcpy(str, " 9+ 8993t489");
   vala = ft_atoi(str);
   printf("String value = %s, Int value = %d\n", str, vala);

   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);
   vala = ft_atoi(str);
   printf("String value = %s, Int value = %d\n", str, vala);

   return(0);
}*/