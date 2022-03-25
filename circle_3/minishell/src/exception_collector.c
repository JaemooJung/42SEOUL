/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_collector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:50:18 by hakim             #+#    #+#             */
/*   Updated: 2022/03/16 12:06:41 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	extract_remainder(t_list *content, t_list **remainder)
{
	if (ft_lstsize(content) < 2)
		return ;
	ft_lstadd_back(remainder, content->next);
	content->next = NULL;
}

static int	open_nodes(t_ast_node *node)
{
	if (node->left->left->right)
	{
		if (node->right->left != NULL)
			return (FAILURE);
		node->right->left = make_ast_node(NODE_FILE_PATH, NULL, NULL);
		if (node->right->left == NULL)
			return (FAILURE);
		node->right->right = make_ast_node(NODE_ARGV, NULL, NULL);
		if (node->right->right == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

static bool	is_in_the_case(t_ast_node *node)
{
	if (node->left == NULL)
		return (false);
	if (node->left->left == NULL)
		return (false);
	if (node->left->left->left == NULL)
		return (false);
	if (node->right->left != NULL)
		return (false);
	return (true);
}

void	search_for_remainder(t_ast_node *node, t_list **remainder)
{
	if (node->node_type == NODE_PHRASE && is_in_the_case(node) == true)
	{
		if (open_nodes(node) == FAILURE)
			return ;
	}
	else if (node->node_type == NODE_PHRASE && is_in_the_case(node) == false)
		return ;
	else if (node->node_type == NODE_FILE_NAME && node->argv != NULL)
		extract_remainder(node->argv, remainder);
	else if (node->node_type == NODE_FILE_PATH && node->file_path == NULL)
	{
		if (*remainder != NULL)
			node->file_path = ft_strdup((*remainder)->line);
		if (node->file_path == NULL)
			return ;
	}
	else if (node->node_type == NODE_ARGV && node->argv == NULL)
	{
		node->argv = *remainder;
		*remainder = NULL;
	}
	if (node->left != NULL)
		search_for_remainder(node->left, remainder);
	if (node->right != NULL)
		search_for_remainder(node->right, remainder);
}
