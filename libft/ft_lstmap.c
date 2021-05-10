/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:44:06 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 18:37:03 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list      *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
    {
        t_list  *new_head;
        t_list  *new_next;
        t_list  *curr;
    
        if (lst == NULL || f == NULL || del == NULL)
    		return (NULL);
        if ((new_head = ft_lstnew(f(lst->content))) == NULL)
            return (NULL);
        curr = new_head;
        lst = lst->next;
        while (lst)
        {
            if ((new_next = ft_lstnew(f(lst->content))) == NULL)
            {
               ft_lstclear(&new_head, del);
               return (NULL);
            }
            curr->next = new_next;
            curr = new_next;
            lst = lst->next;
        }
        return (new_head);
    }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*head;
// 	t_list	*tmp;
// 	t_list	*next;

// 	if (!lst || !f || !del)
// 		return (NULL);
// 	head = ft_lstnew(f(lst->content));
// 	if (!head)
// 		return (NULL);
// 	lst = lst->next;
// 	tmp = head;
// 	while (lst)
// 	{
// 		next = ft_lstnew(f(lst->content));
// 		if (!next)
// 		{
// 			ft_lstclear(&head, del);
// 			return (NULL);
// 		}
// 		tmp->next = next;
// 		tmp = next;
// 		lst = lst->next;
// 	}
// 	return (head);
// }
