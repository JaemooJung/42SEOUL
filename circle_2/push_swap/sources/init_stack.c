/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:16 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/19 13:39:19 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
