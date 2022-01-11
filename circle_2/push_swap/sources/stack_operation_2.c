/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:03 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/11 12:10:20 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
	return (0);
}

int	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}
