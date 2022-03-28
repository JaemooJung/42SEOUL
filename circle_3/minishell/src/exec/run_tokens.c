/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:49 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 15:42:51 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_tree(t_ast_node *node, t_info *info)
{
	if (node->node_type == NODE_PIPE)
	{
		info->mid_status = SUCCESS;
		if (node->right != NULL)
			info->mid_status = lets_pipe(info);
	}
	else if (info->mid_status == SUCCESS && node->node_type == NODE_REDIR_TYPE)
		info->mid_status = teach_me_direction(node->file_path, info);
	else if (info->mid_status == SUCCESS && node->node_type == NODE_FILE_NAME)
		info->mid_status = redir_n_join_remainder(node->argv, info);
	else if (info->mid_status == SUCCESS && node->node_type == NODE_FILE_PATH)
		info->mid_status = get_fullpath(&node->file_path, info);
	else if (info->mid_status == SUCCESS && node->node_type == NODE_ARGV)
		info->exit_status = builtin_or_not(node->argv, info);
}

static void	search_tree(t_ast_node *node, t_info *info)
{
	execute_tree(node, info);
	if (node->left != NULL)
		search_tree(node->left, info);
	if (node->right != NULL)
		search_tree(node->right, info);
}

static void	init_info(t_info *info)
{
	info->mid_status = SUCCESS;
	info->exit_status = SUCCESS;
	info->pipeexists = false;
	info->wasthereanypipe = false;
	info->remainder = NULL;
	info->fd[0] = -1;
	info->fd[1] = -1;
	info->temp_fd = -1;
}

static void	clear_info(t_info *info)
{
	if (info->remainder != NULL)
		ft_free_lst(info->remainder);
	if (info->fd[0] != -1)
		close(info->fd[0]);
	if (info->fd[1] != -1)
		close(info->fd[1]);
	if (info->temp_fd != -1)
		close(info->temp_fd);
	close(info->origin[0]);
	close(info->origin[1]);
}

void	run_tokens(t_ast_node *node, t_list *env, int *exit_status)
{
	t_info	info;
	int		heredoc;

	info.env = env;
	init_info(&info);
	if (keep_stdio(info.origin) == FAILURE)
		ft_print_error(NULL, NULL, strerror(errno));
	search_tree(node, &info);
	if (restore_stdio(info.origin) == FAILURE)
		ft_print_error(NULL, NULL, strerror(errno));
	heredoc = open("mvs_temp", O_RDONLY);
	if (heredoc >= 0)
	{
		close(heredoc);
		if (unlink("mvs_temp") == -1)
			ft_print_error(NULL, NULL, strerror(errno));
	}
	if (info.mid_status != SUCCESS)
		*exit_status = info.mid_status;
	else
		*exit_status = info.exit_status;
	clear_info(&info);
}
