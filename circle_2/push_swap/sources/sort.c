#include "push_swap.h"

void sort_three_a(t_stack **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->top->value;
	middle = (*stack)->top->next->value;
	bottom = (*stack)->bottom->value;
	if (top < middle && middle < bottom)
		return ;
	else if (top > middle && top < bottom)
		sa(stack);
	else if (top > middle && middle > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack);
	else if (top < middle && bottom < middle)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && bottom < middle && bottom < top)
		rra(stack);
	return ;
}

void sort_three_b(t_stack **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->top->value;
	middle = (*stack)->top->next->value;
	bottom = (*stack)->bottom->value;
	if (top < middle && middle < bottom)
		return ;
	else if (top > middle && top < bottom)
		sb(stack);
	else if (top > middle && middle > bottom)
	{
		sb(stack);
		rrb(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		rb(stack);
	else if (top < middle && bottom < middle)
	{
		sb(stack);
		rb(stack);
	}
	else if (top < middle && bottom < middle && bottom < top)
		rrb(stack);
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
	}
	j = 0;
	k = 0;
	while (j++ < ra_count)
		rra(a);
	while (k++ < rb_count)
		rrb(b);
	a_to_b(a, b, ra_count);
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
		sort_three_b(b);
		return ;
	}
	set_pivot(&bigger, &smaller, a);
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