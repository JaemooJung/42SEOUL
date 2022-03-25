/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:43 by hakim             #+#    #+#             */
/*   Updated: 2022/03/16 12:06:05 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	input_redir(char *content, t_info *info)
{
	if (info->prev_dir == IN_REDIR)
		info->fd[INFILE] = mvs_open(content, READ);
	else if (info->prev_dir == IN_HEREDOC)
	{
		info->temp_fd = dup(STDOUT_FILENO);
		if (info->temp_fd == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
		if (dup2(info->origin[0], STDIN_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
		if (dup2(info->origin[1], STDOUT_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
		info->fd[INFILE] = mvs_open("mvs_temp", WRITE);
		here_doc(info->fd[INFILE], content);
		if (dup2(info->temp_fd, STDOUT_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
	}
	if (info->fd[INFILE] == -1)
		return (ft_print_error(NULL, content, strerror(errno)));
	if (dup2(info->fd[INFILE], STDIN_FILENO) == -1)
		return (ft_print_error("Dup didn't work!", NULL, NULL));
	return (SUCCESS);
}

static int	output_redir(char *content, t_info *info)
{
	if (info->prev_dir == OUT_REDIR)
	{
		info->fd[OUTFILE] = mvs_open(content, WRITE);
		if (info->fd[OUTFILE] == -1)
			return (ft_print_error(NULL, content, strerror(errno)));
		if (dup2(info->fd[OUTFILE], STDOUT_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
	}
	else if (info->prev_dir == OUT_APPEND)
	{
		info->fd[OUTFILE] = mvs_open(content, APPEND);
		if (info->fd[OUTFILE] == -1)
			return (ft_print_error(NULL, content, strerror(errno)));
		if (dup2(info->fd[OUTFILE], STDOUT_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
	}
	return (SUCCESS);
}

int	redir_n_join_remainder(t_list *content, t_info *info)
{
	int	stat;

	stat = SUCCESS;
	if (info->fd[INFILE] != -1)
		close(info->fd[INFILE]);
	if (info->fd[OUTFILE] != -1)
		close(info->fd[OUTFILE]);
	if (ft_lstsize(content) > 1)
	{
		ft_lstadd_back(&info->remainder, content->next);
		content->next = NULL;
	}
	if (info->prev_dir == IN_REDIR || info->prev_dir == IN_HEREDOC)
	{
		if (input_redir(content->line, info) == FAILURE)
			stat = FAILURE;
	}
	else if (info->prev_dir == OUT_REDIR || info->prev_dir == OUT_APPEND)
	{
		if (output_redir(content->line, info) == FAILURE)
			stat = FAILURE;
	}
	if (stat == FAILURE)
		info->pipeexists = false;
	return (stat);
}
