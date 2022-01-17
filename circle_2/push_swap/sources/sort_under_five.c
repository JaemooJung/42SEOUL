#include "push_swap.h"

void	sort_three(t_stack **stack)
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
		print_stack_info(*stack, 'a');
		rra(stack);
		print_stack_info(*stack, 'a');
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