/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_n_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:39 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 15:42:41 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	keep_stdio(int *origin)
{
	origin[0] = dup(STDIN_FILENO);
	if (origin[0] == -1)
		return (ft_print_error("Dup didn't work!", NULL, NULL));
	origin[1] = dup(STDOUT_FILENO);
	if (origin[0] == -1)
		return (ft_print_error("Dup didn't work!", NULL, NULL));
	return (SUCCESS);
}

int	restore_stdio(int *origin)
{
	if (dup2(origin[0], STDIN_FILENO) == -1)
		return (ft_print_error("Dup didn't work!", NULL, NULL));
	if (dup2(origin[1], STDOUT_FILENO) == -1)
		return (ft_print_error("Dup didn't work!", NULL, NULL));
	return (SUCCESS);
}

int	lets_pipe(t_info *info)
{
	if (pipe(info->pipe) == -1)
		return (ft_print_error("Your pipe needs MARIO!", NULL, NULL));
	info->pipeexists = true;
	info->wasthereanypipe = true;
	return (SUCCESS);
}
