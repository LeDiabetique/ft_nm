/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:04:51 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/07 07:54:07 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	j;

	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen((char *)s) < len)
	{
		j = ft_strlen(s + start) + 1;
		s1 = malloc(sizeof(char) * j);
	}
	else
	{
		j = len + 1;
		s1 = malloc(sizeof(char) * j);
	}
	if (s1 == 0)
		return (0);
	j = ft_strlcpy(s1, &s[start], j);
	return (s1);
}
/*
int main()
{
	char *str;
	
	str = ft_substr("test", 1, 6);
	printf("%s",str);
}*/
