/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:41:54 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/20 14:36:36 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr(t_stack **a, int size)
{
	int		*arr;
	int		i;
	t_node	*tmp;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	tmp = (*a)->top;
	while (i < size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	arr_swap(int *first, int *second)
{
	int	tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void	quick_sort(int **arr, int l, int r)
{
	int		i;
	int		j;
	int		pivot;

	i = l;
	j = r;
	pivot = (*arr)[(l + r) / 2];
	while (i <= j)
	{
		while ((*arr)[i] < pivot)
			i++;
		while ((*arr)[j] > pivot)
			j--;
		if (i <= j)
		{
			arr_swap(&(*arr)[i], &(*arr)[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quick_sort(arr, l, j);
	if (i < r)
		quick_sort(arr, i, r);
}

void	set_pivot(t_vars *vars, t_stack **stack, int size)
{
	int		*arr;
	double	s_idx;
	double	b_idx;

	arr = make_arr(stack, size);
	if (arr == NULL)
		error_handler();
	quick_sort(&arr, 0, size - 1);
	s_idx = size * (0.33);
	b_idx = size * (0.66);
	vars->bigger = arr[(int)s_idx];
	vars->smaller = arr[(int)b_idx];
	free(arr);
}
