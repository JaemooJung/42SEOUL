#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b, int size)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
	if (size < 3)
	{
		sort_under_three_a(a, size);
		return ;
	}
	set_pivot(&vars, a);
	compair_and_move_a(a, b, &vars, size);
	re_rotate(a, b,&vars);
	a_to_b(a, b, vars.ra_cnt);
	b_to_a(a, b, vars.rb_cnt);
	b_to_a(a, b, vars.pb_cnt - vars.rb_cnt);
}

void	b_to_a(t_stack **a, t_stack **b, int size)
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(t_vars));
	if (size < 3)
	{
		sort_under_three_b(a, b, size);
		return ;
	}
	set_pivot(&vars, b);
	compair_and_move_b(a, b, &vars, size);
	a_to_b(a, b, vars.pa_cnt - vars.ra_cnt);
	re_rotate(a, b,&vars);
	a_to_b(a, b, vars.ra_cnt);
	b_to_a(a, b, vars.rb_cnt);
}
