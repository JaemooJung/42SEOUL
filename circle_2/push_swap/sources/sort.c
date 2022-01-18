#include "push_swap.h"

void	set_pivot(int *bigger, int *smaller, t_stack **a)
{
	int	first;
	int	second;

	first = (*a)->top->value;
	second = (*a)->top->next->value;
	if (first + 1 == second || first - 1 == second)
	second = (*a)->top->next->next->value;
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
		sort_under_three_a(a, size);
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
		if ((*a)->top != NULL)
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
		sort_under_three_b(a, b, size);
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
		if ((*b)->top != NULL)
			tmp = (*b)->top->value;
	}
	a_to_b(a, b, pa_count - ra_count);
	j = 0;
	k = 0;
	while (j++ < ra_count)
		rra(a);
	while (k++ < rb_count)
		rrb(b);
	a_to_b(a, b, ra_count);
	b_to_a(a, b, rb_count);
}
