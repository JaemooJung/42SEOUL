/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:56 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/20 13:49:13 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b, int size, int *flag)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	if (size <= 3)
	{
		sort_under_three_a(a, size);
		return ;
	}
	set_pivot(&vars, a, size);
	compair_and_move_a(a, b, &vars, size);
	re_rotate_ab(a, b, &vars, *flag);
	a_to_b(a, b, vars.ra_cnt, flag);
	b_to_a(a, b, vars.rb_cnt, flag);
	b_to_a(a, b, vars.pb_cnt - vars.rb_cnt, flag);
}

void	b_to_a(t_stack **a, t_stack **b, int size, int *flag)
{
	t_vars	vars;

	(*flag)++;
	ft_bzero(&vars, sizeof(t_vars));
	if (size <= 3)
	{
		sort_under_three_b(a, b, size);
		return ;
	}
	set_pivot(&vars, b, size);
	compair_and_move_b(a, b, &vars, size);
	a_to_b(a, b, vars.pa_cnt - vars.ra_cnt, flag);
	re_rotate_ba(a, b, &vars);
	a_to_b(a, b, vars.ra_cnt, flag);
	b_to_a(a, b, vars.rb_cnt, flag);
}
