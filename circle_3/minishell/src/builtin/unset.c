/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:34:55 by hakim             #+#    #+#             */
/*   Updated: 2022/03/16 12:04:13 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_identifier(char *str)
{
	if (ft_strchr(str, '=') != NULL)
		return (false);
	if (ft_isalpha(str[0]) == 0)
		return (false);
	return (true);
}

static void	delete_head(t_list **env)
{
	t_list	*temp;

	if ((*env)->next == NULL)
	{
		delete_node(*env);
		return ;
	}
	temp = *env;
	*env = temp->next;
	delete_node(temp);
}

static void	find_n_remove(t_list *env, char *str)
{
	while (env != NULL)
	{
		if (ft_strncmp(env->line, str, ft_strlen(str)) == 0
			&& (env->line[ft_strlen(str)] == '='
				|| env->line[ft_strlen(str)] == '\0'))
		{
			if (env->prev == NULL)
				delete_head(&env);
			else
				delete_node(env);
			return ;
		}
		env = env->next;
	}
}

int	mvs_unset(char **chunk, t_list *env)
{
	int		index;
	int		exit_status;

	index = 1;
	exit_status = SUCCESS;
	while (chunk[index] != NULL)
	{
		if (is_valid_identifier(chunk[index]) == false)
		{
			ft_putstr_fd("unset: \'", STDERR_FILENO);
			ft_putstr_fd(chunk[index], STDERR_FILENO);
			ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
			exit_status = FAILURE;
		}
		else
			find_n_remove(env, chunk[index]);
		++index;
	}
	return (exit_status);
}
