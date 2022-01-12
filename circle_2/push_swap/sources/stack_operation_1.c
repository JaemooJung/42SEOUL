/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:05 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/12 14:46:39 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **a)
{
	if (swap(a) == 0)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_stack **b)
{
	if(swap(b) == 0)
		ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_stack **a, t_stack **b)
{
	if (swap(a) == 0 && swap(b) == 0)
		ft_putstr_fd("ss\n", 1);
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push(b, a) == 0)
		ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push(a, b) == 0)
		ft_putstr_fd("pb\n", 1);
	return (0);
}
