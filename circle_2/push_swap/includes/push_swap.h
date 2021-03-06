/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:00 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/24 17:16:37 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node	t_node;
struct	s_node
{
	int			value;
	t_node		*prev;
	t_node		*next;
};

typedef struct s_stack
{
	int			size;
	t_node		*top;
	t_node		*bottom;
}				t_stack;

typedef struct s_five_vars
{
	int		median;
	int		cnt;
	int		r_cnt;
}			t_five_vars;

typedef struct s_vars
{
	int	bigger;
	int	smaller;
	int	tmp;
	int	i;
	int	j;
	int	k;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	pb_cnt;
}		t_vars;

int			check_arguments_and_append(int argc, char **argv, t_node **node);
void		dupcheck_and_append(t_node **head, t_node *new_node);
void		append(t_node **head, t_node *new_node);
t_node		*new_node(int value);

int			init_stacks(t_node **node, t_stack **a, t_stack **b);

int			push(t_stack **from, t_stack **to);
int			swap(t_stack **stack);
int			rotate(t_stack **stack);
int			reverse_rotate(t_stack **stack);

int			sa(t_stack **a);
int			sb(t_stack **b);
int			ss(t_stack **a, t_stack **b);
int			pa(t_stack **a, t_stack **b);
int			pb(t_stack **a, t_stack **b);
int			ra(t_stack **a);
int			rb(t_stack **b);
int			rr(t_stack **a, t_stack **b);
int			rra(t_stack **a);
int			rrb(t_stack **b);
int			rrr(t_stack **a, t_stack **b);

void		a_to_b(t_stack **a, t_stack **b, int size, int *flag);
void		b_to_a(t_stack **a, t_stack **b, int size, int *flag);

void		sort_under_three_a(t_stack **a, int size);
void		sort_three_for_a(t_stack **stack);
void		sort_three_arg_for_a(t_stack **a);

void		sort_three_for_b(t_stack **b);
void		sort_under_three_b(t_stack **a, t_stack **b, int size);

void		sort_five_for_a(t_stack **a, t_stack **b);
void		sort_five_arg_for_a(t_stack **a, t_stack **b);
void		sort_five_for_b(t_stack **a, t_stack **b);

void		check_and_push_a(t_stack **a, t_stack **b,
				t_five_vars *vars);
void		check_and_push_b(t_stack **a, t_stack **b,
				t_five_vars *vars);
void		compair_and_move_a(t_stack **a, t_stack **b, t_vars *vars,
				int size);
void		compair_and_move_b(t_stack **a, t_stack **b, t_vars *vars,
				int size);

int			*make_arr(t_stack **a, int size);
void		quick_sort(int **arr, int l, int r);
void		set_pivot(t_vars *vars, t_stack **a, int size);
int			is_a_sorted(t_stack **a, int size);
int			is_b_sorted(t_stack **b, int size);

void		re_rotate_ab(t_stack **a, t_stack **b, t_vars *vars, int flag);
void		re_rotate_ba(t_stack **a, t_stack **b, t_vars *vars);
void		error_handler(void);

#endif