/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:00:18 by hakim             #+#    #+#             */
/*   Updated: 2022/03/06 22:00:24 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*copy_list(t_list *src)
{
	t_list	*dst;
	t_list	*cur;

	dst = ft_lstnew(src->line);
	if (dst == NULL)
		return (NULL);
	cur = dst;
	src = src->next;
	while (src != NULL)
	{
		ft_lstadd_back(&dst, ft_lstnew(src->line));
		src = src->next;
		cur = cur->next;
		if (cur == NULL)
			return (ft_free_lst(dst));
	}
	return (dst);
}

static void	swap_values(t_list *a, t_list *b)
{
	char	*swap;

	swap = a->line;
	a->line = b->line;
	b->line = swap;
}

t_list	*sort_list(t_list *lst, int (*cmp)(const char *, const char *, size_t))
{
	int		swapped;
	t_list	*cur;
	size_t	longer;

	swapped = 1;
	cur = lst;
	while (swapped == 1)
	{
		swapped = 0;
		while (cur != NULL && cur->next != NULL)
		{
			longer = ft_strlen(cur->line);
			if (ft_strlen(cur->next->line) > longer)
				longer = ft_strlen(cur->next->line);
			if (cmp(cur->line, cur->next->line, longer) > 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	size;

	if (lst == 0)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}
