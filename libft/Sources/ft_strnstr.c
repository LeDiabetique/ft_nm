/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:40:26 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/11 15:18:53 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*b, const char	*l, size_t i)
{
	size_t	n;
	size_t	y;

	n = 0;
	if (b == NULL && i == 0)
		return ((char *)b);
	if (l[n] == '\0')
		return ((char *)b);
	if (!l)
		return (NULL);
	while (b[n] && n < i)
	{
		y = 0;
		while (b[n + y] == l[y] && (n + y) < i)
		{
			y++;
			if (y == ft_strlen(l))
				return ((char *)&b[n]);
		}
		n++;
	}
	return (NULL);
}
/*int main ()
{
	const char *largestring = "aaabcabcd";
    const char *smallstring = "cd";
    char *ptr;
	char *ptr2;
	ptr = ft_strnstr(largestring,smallstring, 8);
	ptr2 = strnstr(largestring, smallstring, 8);

	printf("%s\n", ptr);
	printf("%s", ptr2);
}*/
