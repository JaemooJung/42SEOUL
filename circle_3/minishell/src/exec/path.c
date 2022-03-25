/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:35 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 15:42:37 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_if_dir(char *path)
{
	int	fd;
	DIR	*dir;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (SUCCESS);
	if (ft_strchr(path, '/') != NULL)
	{
		dir = opendir(path);
		if (dir == NULL)
			return (SUCCESS);
		ft_print_error(path, NULL, "is a directory");
		closedir(dir);
		return (126);
	}
	return (SUCCESS);
}

static char	*make_path(char *cmd, char *path)
{
	char	*temp;

	temp = ft_strjoin("/", cmd);
	if (temp == NULL)
		return (NULL);
	path = ft_strjoin(path, temp);
	if (path == NULL)
	{
		ft_free_str(temp);
		return (NULL);
	}
	ft_free_str(temp);
	return (path);
}

static int	concat_path(char **cmd, t_list *env, int i)
{
	char	**paths;
	char	*path;

	if (get_value(env, "PATH") == NULL)
		return (12700);
	paths = ft_split(get_value(env, "PATH"), ':');
	if (paths == NULL)
		return (FAILURE);
	while (paths[i] != NULL)
	{
		path = make_path(*cmd, paths[i++]);
		if (path == NULL)
			return (FAILURE);
		if (open_for_check(path) == SUCCESS)
		{
			ft_free_vector(paths);
			ft_free_str(*cmd);
			*cmd = path;
			return (SUCCESS);
		}
		ft_free_str(path);
	}
	ft_free_vector(paths);
	return (127);
}

static int	what_if_failed_to_find_path(char **content, t_info *info)
{
	if (open_for_check(*content) == SUCCESS)
	{
		info->fullpath = *content;
		return (SUCCESS);
	}
	else
	{
		if (ft_strchr(*content, '/') != NULL)
			ft_print_error(*content, NULL, "No such file or directory");
		else
			ft_print_error("command not found", NULL, *content);
		info->exit_status = 127;
		return (127);
	}
}

int	get_fullpath(char **content, t_info *info)
{
	int	stat;

	if (*content == NULL)
		return (SUCCESS);
	if (classify_builtin(*content) != NONE)
		return (SUCCESS);
	stat = check_if_dir(*content);
	if (stat != SUCCESS)
		return (stat);
	stat = concat_path(content, info->env, 0);
	if (stat == SUCCESS)
		info->fullpath = *content;
	else if (stat == FAILURE)
		ft_print_error(NULL, NULL, strerror(errno));
	else if (stat == 127)
		stat = what_if_failed_to_find_path(content, info);
	else if (stat == 12700)
	{
		ft_print_error(*content, NULL, "No such file or directory");
		info->exit_status = 127;
		stat = 127;
	}
	if (stat != SUCCESS)
		info->pipeexists = false;
	return (stat);
}
