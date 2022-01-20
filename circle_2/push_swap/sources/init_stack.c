/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:16 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/20 12:39:57 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_node **node, t_stack **a, t_stack **b)
{
	int		i;
	t_node	*tmp;

	i = 1;
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	tmp = *node;
	(*a)->top = tmp;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	(*a)->bottom = tmp;
	(*a)->size = i;
	(*b)->top = NULL;
	(*b)->bottom = NULL;
	(*b)->size = 0;
	return (0);
}
