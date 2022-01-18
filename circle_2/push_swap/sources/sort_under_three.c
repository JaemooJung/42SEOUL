#include "push_swap.h"

void	sort_under_three_for_a(t_stack **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->top->value;
	middle = (*stack)->top->next->value;
	bottom = (*stack)->bottom->value;
	if (top > middle && top < bottom && middle < bottom)
		sa(stack);
	else if (top > middle && middle > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack);
	else if (top < middle && bottom < middle && top < bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < middle && bottom < middle && bottom < top)
		rra(stack);
	return ;
}

void sort_three_a(t_stack **a, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->top->value > (*a)->top->next->value)
			sa(a);
		return ;
	}
	else if (size == 3)
	{
		sort_three_for_a(a);
		return ;
	}
	return ;
}

void sort_three_b(t_stack **a, t_stack **b, int size)
{
	if (size == 0)
		return ;
	if (size == 1)
	{
		pa(a, b);
		return;
	}
	else
	{
		if ((*b)->top->value > (*b)->top->next->value)
			sb(b);
	}
	while (size-- > 0)
		pa(a, b);
	return ;
}