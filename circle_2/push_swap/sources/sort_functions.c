/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:40:46 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/20 15:32:07 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compair_and_move_a(t_stack **a, t_stack **b, t_vars *vars, int size)
{
	vars->tmp = (*a)->top->value;
	while (vars->i++ < size)
	{
		if (vars->tmp >= vars->bigger)
		{
			ra(a);
			vars->ra_cnt++;
		}
		else
		{
			pb(a, b);
			vars->pb_cnt++;
			if (vars->tmp >= vars->smaller)
			{
				rb(b);
				vars->rb_cnt++;
			}
		}
		if ((*a)->top != NULL)
			vars->tmp = (*a)->top->value;
	}
}

void	compair_and_move_b(t_stack **a, t_stack **b, t_vars *vars, int size)
{
	vars->tmp = (*b)->top->value;
	while (vars->i++ < size)
	{
		if (vars->tmp < vars->smaller)
		{
			rb(b);
			vars->rb_cnt++;
		}
		else
		{
			pa(a, b);
			vars->pa_cnt++;
			if (vars->tmp < vars->bigger)
			{
				ra(a);
				vars->ra_cnt++;
			}
		}
		if ((*b)->top != NULL)
			vars->tmp = (*b)->top->value;
	}
}

void	re_rotate_ab(t_stack **a, t_stack **b, t_vars *vars, int flag)
{
	int	temp_ra_cnt;
	int	temp_rb_cnt;

	temp_ra_cnt = vars->ra_cnt;
	temp_rb_cnt = vars->rb_cnt;
	while (temp_ra_cnt != 0 && temp_rb_cnt != 0 && flag != 0)
	{
		rrr(a, b);
		temp_ra_cnt--;
		temp_rb_cnt--;
	}
	if (temp_ra_cnt > 0 && flag != 0)
	{
		while (temp_ra_cnt--)
			rra(a);
	}
	if (temp_rb_cnt > 0)
	{
		while (temp_rb_cnt--)
			rrb(b);
	}
}

void	re_rotate_ba(t_stack **a, t_stack **b, t_vars *vars)
{
	int	temp_ra_cnt;
	int	temp_rb_cnt;

	temp_ra_cnt = vars->ra_cnt;
	temp_rb_cnt = vars->rb_cnt;
	while (temp_ra_cnt != 0 && temp_rb_cnt != 0)
	{
		rrr(a, b);
		temp_ra_cnt--;
		temp_rb_cnt--;
	}
	if (temp_ra_cnt > 0)
	{
		while (temp_ra_cnt--)
			rra(a);
	}
	else if (temp_rb_cnt > 0)
	{
		while (temp_rb_cnt--)
			rrb(b);
	}
}
