/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:52:53 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/22 10:33:46 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_a_sorted(t_stack **a, int size)
{
	t_node	*tmp;

	tmp = (*a)->top;
	while (size--)
	{
		if (tmp->next != NULL && tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_b_sorted(t_stack **b, int size)
{
	t_node	*tmp;

	tmp = (*b)->top;
	while (size--)
	{
		if (tmp->next != NULL && tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}