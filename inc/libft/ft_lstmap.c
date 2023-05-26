/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:41:00 by ARTHUR            #+#    #+#             */
/*   Updated: 2022/12/19 15:19:49 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	t_list	*tmp;

	new_elem = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = (*f)(lst->content);
		new_list = ft_lstnew(tmp);
		if (!new_list)
		{
			free(tmp);
			ft_lstclear(&new_elem, del);
			return (NULL);
		}
		ft_lstadd_back(&new_elem, new_list);
		lst = lst->next;
	}
	return (new_elem);
}
