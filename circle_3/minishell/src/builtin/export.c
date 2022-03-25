/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:34:44 by hakim             #+#    #+#             */
/*   Updated: 2022/03/01 14:34:44 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_exported_quoted(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != '=')
			write(STDOUT_FILENO, &str[index], 1);
		else
		{
			write(STDOUT_FILENO, &str[index], 1);
			write(STDOUT_FILENO, "\"", 1);
		}
		++index;
	}
	write(STDOUT_FILENO, "\"\n", 2);
}

static int	ft_strncmp_for_sort(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((index < n) && (s1[index] != '\0' || s2[index] != '\0'))
	{
		if (s1[index] == '=')
			return (0 - (unsigned char)s2[index]);
		else if (s2[index] == '=')
			return ((unsigned char)s1[index]);
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

static void	*ft_free_lst_wo_dup(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	free(lst);
	lst = NULL;
	return (NULL);
}

static int	print_sorted(t_list *env)
{
	t_list	*temp;
	t_list	*cur;

	temp = copy_list(env);
	if (temp == NULL)
		return (FAILURE);
	sort_list(temp, ft_strncmp_for_sort);
	cur = temp;
	while (cur != NULL)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		if (ft_strchr(cur->line, '=') != NULL)
			print_exported_quoted(cur->line);
		else
			ft_putendl_fd(cur->line, STDOUT_FILENO);
		cur = cur->next;
	}
	ft_free_lst_wo_dup(temp);
	return (SUCCESS);
}

int	mvs_export(char **chunk, t_list *env)
{
	int		index;
	int		exit_status;

	index = 0;
	exit_status = SUCCESS;
	while (chunk[index] != NULL)
		++index;
	if (index == 1)
		exit_status = print_sorted(env);
	else
	{
		index = 1;
		while (chunk[index] != NULL)
		{
			if (append_to_env(env, chunk[index]) != SUCCESS)
				exit_status = FAILURE;
			++index;
		}
	}
	return (exit_status);
}
