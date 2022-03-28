/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:18 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 16:06:19 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (lst);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
		if (new->prev != NULL)
			new->prev = NULL;
		return ;
	}
	new->prev = ft_lstlast(*lst);
	new->prev->next = new;
}

t_list	*ft_lstnew(char *line)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->line = line;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void	delete_node(t_list *lst)
{
	if (lst->prev == NULL && lst->next == NULL)
		;
	else if (lst->prev == NULL)
		lst->next->prev = NULL;
	else if (lst->next == NULL)
		lst->prev->next = NULL;
	else
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
	ft_free_str(lst->line);
	free(lst);
	lst = NULL;
}

void	*ft_free_lst(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		temp = lst->next;
		delete_node(lst);
		lst = temp;
	}
	delete_node(lst);
	return (NULL);
}
