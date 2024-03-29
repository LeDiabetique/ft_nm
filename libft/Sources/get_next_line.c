/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:48:58 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/10 08:58:26 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_readadd(int fd, char *str)
{
	char	*buffer;
	int		i;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		str = ft_joinfree(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*ft_joinfree(char *str, char *buf)
{
	char	*temp;

	temp = ft_strjoin(str, buf);
	free(str);
	return (temp);
}

static char	*ft_before(char	*buf)
{
	char	*dest;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	dest = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		dest[i++] = '\n';
	return (dest);
}

static char	*ft_after(char	*buf)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	dest = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		dest[j++] = buf[i++];
	free(buf);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_readadd(fd, str);
	if (!str)
		return (NULL);
	line = ft_before(str);
	str = ft_after(str);
	return (line);
}
