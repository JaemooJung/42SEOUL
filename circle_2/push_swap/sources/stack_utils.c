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