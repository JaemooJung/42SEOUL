/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:48:43 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/15 15:46:33 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*make_ast_node(int node_type, char *file_path, t_list *argv)
{
	t_ast_node	*node;

	node = (t_ast_node *)malloc(sizeof(t_ast_node));
	if (node == NULL)
		return (NULL);
	node->node_type = node_type;
	node->file_path = file_path;
	node->argv = argv;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_ast_node	*ast_insert_node(t_ast_node *root, t_ast_node *node, int side)
{
	if (root == NULL)
	{
		root = node;
		return (root);
	}
	else
	{
		if (side == LEFT)
			root->left = ast_insert_node(root->left, node, side);
		else
			root->right = ast_insert_node(root->right, node, side);
		return (root);
	}
}

void	clear_ast(t_ast_node *root)
{
	if (root == NULL)
		return ;
	clear_ast(root->left);
	clear_ast(root->right);
	if (root->file_path != NULL)
	{
		free(root->file_path);
		root->file_path = NULL;
	}
	if (root->argv != NULL)
	{
		ft_free_lst(root->argv);
		root->argv = NULL;
	}
	free(root);
	root = NULL;
}
