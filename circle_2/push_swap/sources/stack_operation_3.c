/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:09:59 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/13 10:25:01 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrr(t_stack **a, t_stack **b)
{
	if (reverse_rotate(a) == 0 && reverse_rotate(b) == 0)
		ft_putstr_fd("rrr\n", 1);
	return (0);
}
