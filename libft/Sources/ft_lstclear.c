/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:34:39 by hdiot             #+#    #+#             */
/*   Updated: 2022/12/06 08:07:07 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	if (!lst || !del)
		return ;
	while (tmp)
	{
		tmp2 = tmp2->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
