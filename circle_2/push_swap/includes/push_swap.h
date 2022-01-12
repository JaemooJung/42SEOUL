/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:00 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/12 14:10:18 by jaemoojung       ###   ########.fr       */
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

int		check_arguments_and_append(int argc, char **argv, t_node **node);
void	dupcheck_and_append(t_node **head, t_node *new_node);
void	append(t_node **head, t_node *new_node);
t_node	*new_node(int value);


void	print_stack_info(t_stack *stack, char stack_name); //TODO : 나중에 지우기
int		init_stacks(t_node **node, t_stack **a, t_stack **b);

int		push(t_stack **from, t_stack **to);
int		swap(t_stack **stack);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);

void	error_handler(void);

long long	ft_atoi(char *str);

#endif