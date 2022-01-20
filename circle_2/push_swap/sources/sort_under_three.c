/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:52 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/20 12:40:53 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_arg_for_a(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->top->value;
	middle = (*a)->top->next->value;
	bottom = (*a)->bottom->value;
	if (top > middle && top < bottom && middle < bottom)
		sa(a);
	else if (top > middle && middle > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top < middle && bottom < middle && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && bottom < middle && bottom < top)
		rra(a);
	return ;
}

void	sort_three_for_a(t_stack **a)
{
	if ((*a)->top->value < (*a)->top->next->value
		&& (*a)->top->next->value < (*a)->top->next->next->value)
		return ;
	if ((*a)->top->value > (*a)->top->next->value
		&& (*a)->top->value > (*a)->top->next->next->value)
		sa(a);
	if ((*a)->top->value < (*a)->top->next->value)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	if ((*a)->top->value > (*a)->top->next->value)
		sa(a);
}

void	sort_three_for_b(t_stack **b)
{
	if ((*b)->top->value > (*b)->top->next->value
		&& (*b)->top->next->value > (*b)->top->next->next->value)
		return ;
	if ((*b)->top->value < (*b)->top->next->value
		&& (*b)->top->value < (*b)->top->next->next->value)
		sb(b);
	if ((*b)->top->value > (*b)->top->next->value)
	{
		rb(b);
		sb(b);
		rrb(b);
	}
	if ((*b)->top->value < (*b)->top->next->value)
		sb(b);
}

void	sort_under_three_a(t_stack **a, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->top->value > (*a)->top->next->value)
			sa(a);
		return ;
	}
	else if (size == 3)
	{
		if ((*a)->size == 3)
			sort_three_arg_for_a(a);
		else
			sort_three_for_a(a);
	}
	return ;
}

void	sort_under_three_b(t_stack **a, t_stack **b, int size)
{
	if (size == 0)
		return ;
	if (size == 1)
	{
		pa(a, b);
		return ;
	}
	if (size == 2)
	{
		if ((*b)->top->value < (*b)->top->next->value)
			sb(b);
	}
	else if (size == 3)
		sort_three_for_b(b);
	while (size-- > 0)
		pa(a, b);
	return ;
}
