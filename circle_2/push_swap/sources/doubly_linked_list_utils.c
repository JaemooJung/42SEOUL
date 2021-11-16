/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:11 by jaemjung          #+#    #+#             */
/*   Updated: 2021/11/16 17:19:31 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_duplicated(t_node *curr, t_node *new_node)
{
	if (curr->value == new_node->value)
		return (1);
	return (0);
}

t_node	*new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	dupcheck_and_append(t_node **head, t_node *new_node)
{
	t_node	*curr;

	if (new_node == NULL)
		error_handler();
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
	{
		if (is_duplicated(curr, new_node))
			error_handler();
		curr = curr->next;
	}
	if (is_duplicated(curr, new_node))
		error_handler();
	curr->next = new_node;
	new_node->prev = curr;
}

void	append(t_node **head, t_node *new_node)
{
	t_node	*curr;

	if (new_node == NULL)
		error_handler();
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
}
