/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:58:08 by hakim             #+#    #+#             */
/*   Updated: 2022/03/17 11:50:07 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum(int c)
{
	if ('0' <= c && c <= '9')
		return (42);
	else if ('a' <= c && c <= 'z')
		return (42);
	else if ('A' <= c && c <= 'Z')
		return (42);
	else if (c == '_')
		return (42);
	return (0);
}

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (42);
	else if (c == '_')
		return (42);
	return (0);
}

int	ft_free_str(char *str)
{
	free(str);
	str = NULL;
	return (FAILURE);
}

int	ft_print_error(char *cmd, char *arg, char *error)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (cmd != NULL)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (arg != NULL)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (error != NULL)
		ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (FAILURE);
}

void	ft_free_vector(char **vector)
{
	int	index;

	index = 0;
	while (vector[index] != NULL)
		ft_free_str(vector[index++]);
	free(vector);
	vector = NULL;
}
