/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:49:02 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/05 09:48:28 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t	size)
{
	void	*p;

	if (count && count * size / count != size)
		return (0);
	p = malloc(count * size);
	if (p == NULL)
		return (p);
	ft_bzero(p, size * count);
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!*str && !c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	i = -1;
	while (s2[++i])
		str[len++] = s2[i];
	str[len] = '\0';
	return (str);
}
