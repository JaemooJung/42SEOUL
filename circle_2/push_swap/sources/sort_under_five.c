/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:44:30 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/22 23:48:27 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack **stack, int size)
{
	int	*arr;
	int	median;

	arr = make_arr(stack, size);
	if (arr == NULL)
		error_handler();
	quick_sort(&arr, 0, size - 1);
	median = arr[size / 2];
	free(arr);
	arr = NULL;
	return (median);
}

void	sort_five_arg_for_a(t_stack **a, t_stack **b)
{
	int		median;
	int		cnt;

	if (is_a_sorted(a, 5))
		return ;
	median = get_median(a, 5);
	cnt = 0;
	while (cnt < 2)
	{
		if ((*a)->top->value < median)
		{
			pb(a, b);
			cnt++;
		}
		else
			ra(a);
	}
	sort_three_arg_for_a(a);
	if ((*b)->top->value < (*b)->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_five_for_a(t_stack **a, t_stack **b)
{
	t_five_vars	vars;

	if (is_a_sorted(a, 5))
		return ;
	ft_bzero(&vars, sizeof(t_five_vars));
	vars.median = get_median(a, 5);
	check_and_push_a(a, b, &vars);
	while (vars.r_cnt--)
		rra(a);
	sort_three_for_a(a);
	if ((*b)->top->value < (*b)->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_five_for_b(t_stack **a, t_stack **b)
{
	t_five_vars	vars;
	int			size;

	size = 5;
	if (is_b_sorted(b, size))
	{
		while (size--)
			pa(a, b);
		return ;
	}
	ft_bzero(&vars, sizeof(t_five_vars));
	vars.median = get_median(b, 5);
	check_and_push_b(a, b, &vars);
	if ((*a)->top->value > (*a)->top->next->value)
		sa(a);
	while (vars.r_cnt--)
		rrb(b);
	sort_three_for_b(b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}
