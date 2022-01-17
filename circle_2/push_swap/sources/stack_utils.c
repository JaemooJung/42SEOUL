/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:16 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/01/17 21:24:25 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_stack **from, t_stack **to)
{
	t_node	*node_to_move;
	t_node	*next_top_of_from;

	if ((*from)->size < 1)
		return (-1);
	node_to_move = (*from)->top;
	next_top_of_from = (*from)->top->next;
	if ((*to)->size == 0)
	{
		(*to)->top = node_to_move;
		(*to)->bottom = node_to_move;
		node_to_move->next = NULL;
	}
	else
	{
		node_to_move->next = (*to)->top;
		(*to)->top->prev = node_to_move;
		(*to)->top = node_to_move;
	}
	if (next_top_of_from != NULL)
		next_top_of_from->prev = NULL;
	else
		(*from)->bottom = NULL;
	(*from)->top = next_top_of_from;
	(*to)->size++;
	(*from)->size--;
	return (0);
}

//swap에서 문제 발견씨발
int	swap(t_stack **stack)
{
	t_node	*node_to_go_down;
	t_node	*node_to_go_up;

	if ((*stack)->size < 2)
		return (-1);
	node_to_go_down = (*stack)->top;
	node_to_go_up = (*stack)->top->next;
	node_to_go_down->prev = node_to_go_up;
	node_to_go_down->next = node_to_go_up->next;
	node_to_go_up->prev = NULL;
	node_to_go_up->next = node_to_go_down;
	(*stack)->top = node_to_go_up;
	if (node_to_go_down->next == NULL)
		(*stack)->bottom = node_to_go_down;
	return (0);
}

int rotate(t_stack **stack)
{
	t_node	*next_top;
	t_node	*next_bottom;
	t_node	*former_bottom;

	if ((*stack)->size < 2)
		return (-1);
	next_top = (*stack)->top->next;
	next_bottom = (*stack)->top;
	former_bottom = (*stack)->bottom;
	next_top->prev = NULL;
	next_bottom->next = NULL;
	(*stack)->top = next_top;
	(*stack)->bottom = next_bottom;
	former_bottom->next = next_bottom;
	next_bottom->prev = former_bottom;
	return (0);
}

int reverse_rotate(t_stack **stack)
{
	t_node	*next_top;
	t_node	*next_bottom;
	t_node	*former_top;

	if ((*stack)->size < 2)
		return (-1);
	next_top = (*stack)->bottom;
	next_bottom = (*stack)->bottom->prev;
	former_top = (*stack)->top;
	next_top->prev = NULL;
	next_bottom->next = NULL;
	(*stack)->top = next_top;
	(*stack)->bottom = next_bottom;
	former_top->prev = next_top;
	next_top->next = former_top;
	return (0);
}

//TODO : 나중에 지우기

#include <stdio.h>
void print_stack_info(t_stack *stack, char stack_name)
{
	if (stack->size == 0)
	{
		printf("stack %c is Empty\n", stack_name);
		return ;
	}
	printf("-------------------------------------------------\n");
	printf("stack %c top : %d\n", stack_name, stack->top->value);
	printf("stack %c bottom : %d\n", stack_name, stack->bottom->value);
	printf("stack %c size : %d\n", stack_name, stack->size);

	printf("stack elements : ");
	t_node *tmp = stack->top;
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n-------------------------------------------------");
	printf("\n");
}

// ---------------------