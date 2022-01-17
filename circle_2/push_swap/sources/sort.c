#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b, int size)
{
	int	pivot;
	int	ra_cnt;
	int	pb_cnt;
	int	i;
	int j;

	pivot = (*a)->top->value;
	ra_cnt = 0;
	pb_cnt = 0;
	i = 0;
	j = 0;

	while (i < size)
	{
		if ((*a)->top->value < pivot)
		{
			ra_cnt++;
			ra(a);
		}
		else
		{
			pb_cnt++;
			pb(a, b);
		}
		i++;
		print_stack_info(*a, 'a');
		print_stack_info(*b, 'b');
	}
	while (j < ra_cnt)
	{
		rra(a);
		j++;
		print_stack_info(*a, 'a');
		print_stack_info(*b, 'b');
	}
}

void	b_to_a(t_stack **a, t_stack **b, int size)
{
	(void) a;
	(void) b;
	size = size + 1;
	return ;
}