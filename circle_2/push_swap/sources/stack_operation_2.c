/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:03 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/18 14:56:36 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a)
{
	if (rotate(a) == 0)
	{
		ft_putstr_fd("ra\n", 1);
		return (0);
	}
	return (1);
}

int	rb(t_stack **b)
{
	if (rotate(b) == 0)
	{
		ft_putstr_fd("rb\n", 1);
		return (0);
	}
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) == 0 || rotate(b) == 0)
	{
		ft_putstr_fd("rr\n", 1);
		return (0);
	}
	return (1);
}

int	rra(t_stack **a)
{
	if (reverse_rotate(a) == 0)
	{
		ft_putstr_fd("rra\n", 1);
		return (0);
	}
	return (1);
}

int	rrb(t_stack **b)
{
	if (reverse_rotate(b) == 0)
	{
		ft_putstr_fd("rrb\n", 1);
		return (0);
	}
	return (1);
}
