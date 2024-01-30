/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:15:34 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/07 07:55:39 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*newl;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	newl = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstdelone(tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&newl, tmp);
		lst = lst->next;
	}
	return (newl);
}
