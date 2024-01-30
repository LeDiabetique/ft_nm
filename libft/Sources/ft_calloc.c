/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:44:15 by hdiot             #+#    #+#             */
/*   Updated: 2022/11/17 10:24:17 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
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
