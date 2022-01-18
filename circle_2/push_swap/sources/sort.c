#include "push_swap.h"

void sort_three_a(t_stack **a)
{
	if ((*a)->size == 1)
		return ;
	else if ((*a)->size == 2)
	{
		if ((*a)->top->value > (*a)->top->next->value)
			sa(a);
		return;
	}
	sort_three(a);
		return ;
}

void sort_three_b(t_stack **a, t_stack **b)
{
	if ((*b)->size == 1)
	{
		pa(a, b);
		return;
	}
	else if ((*b)->size == 2)
	{
		if ((*b)->top->value > (*b)->top->next->value)
			sb(b);
	}
	else
		sort_three(b);
	while ((*b)->size > 0)
		pa(a, b);
	return ;
}

void	set_pivot(int *bigger, int *smaller, t_stack **a)
{
	int	first;
	int	second;

	first = (*a)->top->value;
	second = (*a)->bottom->value;
	if (first < second)
	{
		*smaller = first;
		*bigger = second;
	}
	else
	{
		*bigger = first;
		*smaller = second;
	}
}

void	a_to_b(t_stack **a, t_stack **b, int size)
{
	int	bigger;
	int	smaller;
	int	tmp;
	int	i;
	int	j;
	int	k;
	int	ra_count;
	int	pb_count;
	int	rb_count;

	if (size < 3)
	{
		sort_three_a(a);
		return ;
	}
	set_pivot(&bigger, &smaller, a);
	tmp = (*a)->top->value;
	i = 0;
	ra_count = 0;
	pb_count = 0;
	rb_count = 0;
	while (i++ < size)
	{
		if (tmp >= bigger)
		{
			ra(a);
			ra_count++;
		}
		else
		{
			pb(a, b);
			pb_count++;
			if (tmp >= smaller)
			{
				rb(b);
				rb_count++;
			}
		}
		tmp = (*a)->top->value;
	}
	j = 0;
	k = 0;
	while (j++ < ra_count)
		rra(a);
	while (k++ < rb_count)
		rrb(b);
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
	b_to_a(a, b, pb_count - rb_count);
}

void	b_to_a(t_stack **a, t_stack **b, int size)
{
	int	bigger;
	int	smaller;
	int	tmp;
	int	i;
	int	j;
	int	k;
	int	ra_count;
	int	pa_count;
	int	rb_count;

	if (size < 3)
	{
		sort_three_b(a, b);
		return ;
	}
	set_pivot(&bigger, &smaller, b);
	tmp = (*b)->top->value;
	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	i = 0;
	while (i++ < size)
	{
		if (tmp < smaller)
		{
			rb(b);
			rb_count++;
		}
		else
		{
			pa(a, b);
			pa_count++;
			if (tmp < bigger)
			{
				ra(a);
				ra_count++;
			}
		}
		tmp = (*b)->top->value;
	}
	a_to_b(a, b, pa_count - ra_count);
	j = 0;
	k = 0;
	while (j++ < ra_count)
		ra(a);
	while (k++ < rb_count)
		rb(b);
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
}