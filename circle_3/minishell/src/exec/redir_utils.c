/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:46 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 15:42:48 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_for_check(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd >= 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	mvs_open(char *file, int mode)
{
	int	fd;

	if (mode == READ)
		fd = open(file, O_RDONLY, 0644);
	else if (mode == WRITE)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	here_doc(int infile, char *limiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			ft_free_str(line);
			break ;
		}
		write(infile, line, ft_strlen(line));
		write(infile, "\n", 1);
		ft_free_str(line);
	}
	close(infile);
	infile = open("mvs_temp", O_RDONLY, 0644);
	if (infile == -1)
		return (FAILURE);
	return (SUCCESS);
}

int	teach_me_direction(char *content, t_info *info)
{
	if (ft_strncmp(content, "<", 2) == 0)
		info->prev_dir = IN_REDIR;
	else if (ft_strncmp(content, "<<", 3) == 0)
		info->prev_dir = IN_HEREDOC;
	else if (ft_strncmp(content, ">", 2) == 0)
		info->prev_dir = OUT_REDIR;
	else if (ft_strncmp(content, ">>", 3) == 0)
		info->prev_dir = OUT_APPEND;
	else
		return (FAILURE);
	return (SUCCESS);
}
