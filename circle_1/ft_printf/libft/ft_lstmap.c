/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:44:06 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/14 12:15:15 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_head;
	t_list	*mapped_next;
	t_list	*mapped_curr;

	if (!lst || !f)
		return (NULL);
	mapped_head = ft_lstnew(f(lst->content));
	if (!mapped_head)
		return (NULL);
	mapped_curr = mapped_head;
	lst = lst->next;
	while (lst)
	{
		mapped_next = ft_lstnew(f(lst->content));
		if (!mapped_next)
		{
			ft_lstclear(&mapped_head, del);
			return (NULL);
		}
		mapped_curr->next = mapped_next;
		mapped_curr = mapped_next;
		lst = lst->next;
	}
	return (mapped_head);
}
