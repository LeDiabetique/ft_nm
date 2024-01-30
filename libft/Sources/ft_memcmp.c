/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:08:26 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 08:27:54 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void	*p1, const void *p2, size_t i)
{
	unsigned const char	*ps1;
	unsigned const char	*ps2;

	ps1 = (unsigned const char *)p1;
	ps2 = (unsigned const char *)p2;
	while (i)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
		i--;
	}
	return (0);
}
/*int main () 
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdf", 6);
   memcpy(str2, "abcdef", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }

   return(0);
}*/
