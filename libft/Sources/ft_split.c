/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:14:30 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/22 14:41:23 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_countall(char const *str, char c)
{
	int	f;
	int	count;

	f = 0;
	count = 0;
	while (str[f])
	{
		if (str[f] != c && str[f])
			count++;
		while (str[f] != c && str[f])
			f++;
		while (str[f] == c && str[f])
			f++;
	}
	return (count);
}

char	**ft_split(char const	*s, char c)
{
	int		i;
	char	**str;
	int		b;
	int		a;

	i = 0;
	a = 0;
	if (!s)
		return (0);
	str = malloc((sizeof(char *)) * (ft_countall((char *)s, c) + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		b = i;
		while (s[i] != c && s[i])
			i++;
		if (b != i)
			str[a++] = ft_substr(s, b, i - b);
		while (s[i] == c && s[i])
			i++;
	}
	str[a++] = 0;
	return (str);
}
/*void	ft_freetab(void *str, int i)
{
	while (i > 0)
		free(str--);
	free(str);
}*/
