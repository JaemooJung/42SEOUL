/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:34:14 by hakim             #+#    #+#             */
/*   Updated: 2022/03/08 19:01:58 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_white_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

static bool	can_be_atoied(char *str)
{
	int	i;

	i = 0;
	while (is_white_space(str[i]) == true)
		++i;
	while (str[i] != '\0' && is_white_space(str[i]) == false)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (false);
		++i;
	}
	while (is_white_space(str[i]) == true && str[i] != '\0')
		++i;
	if (str[i] == '\0')
		return (true);
	return (false);
}

int	mvs_exit(char **chunk, t_list *env)
{
	int	i;

	(void)env;
	i = 0;
	while (chunk[i] != NULL)
		i++;
	if (i == 1)
	{
		ft_putendl_fd("exit", 1);
		exit(EXIT_SUCCESS);
	}
	if (i > 2)
	{
		ft_putendl_fd("exit\nminishell: exit: too many arguments", 2);
		return (FAILURE);
	}
	if (can_be_atoied(chunk[1]) == false)
	{
		ft_putstr_fd("exit\nminishell: exit: ", 2);
		ft_putstr_fd(chunk[1], 2);
		ft_putendl_fd(" numeric argument required", 2);
		exit(255);
	}
	ft_putendl_fd("exit", 1);
	exit(ft_atoi(chunk[1]));
}
