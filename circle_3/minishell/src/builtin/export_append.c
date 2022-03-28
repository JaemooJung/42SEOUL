/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:46:05 by hakim             #+#    #+#             */
/*   Updated: 2022/03/17 11:46:51 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_identifier(char *str)
{
	int	index;

	if (ft_isalpha(str[0]) == 0)
		return (false);
	index = 0;
	while (str[index] != '\0' && str[index] != '=')
	{
		if (ft_isalnum(str[index]) == 0)
			return (false);
		++index;
	}
	return (true);
}

static size_t	find_equal_or_end(char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0' && str[index] != '=')
		++index;
	return (index);
}

static int	add_new_env(t_list *env, char *str)
{
	char	*new;
	t_list	*temp;

	new = ft_strdup(str);
	if (new == NULL)
		return (FAILURE);
	temp = ft_lstnew(new);
	if (temp == NULL)
	{
		ft_free_str(new);
		return (FAILURE);
	}
	ft_lstadd_back(&env, temp);
	return (SUCCESS);
}

static int	find_n_append(t_list *env, char *str)
{
	size_t	len;
	t_list	*origin;
	char	*new;

	origin = env;
	while (env != NULL)
	{
		len = find_equal_or_end(str);
		if (ft_strncmp(env->line, str, len) == 0
			&& (env->line[len] == '=' || env->line[len] == '\0'))
		{
			if (ft_strchr(str, '=') != NULL)
			{
				new = ft_strdup(str);
				if (new == NULL)
					return (FAILURE);
				ft_free_str(env->line);
				env->line = new;
			}
			return (SUCCESS);
		}
		env = env->next;
	}
	return (add_new_env(origin, str));
}

int	append_to_env(t_list *env, char *str)
{
	if (is_valid_identifier(str) == false)
	{
		ft_putstr_fd("export: \'", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
		return (FAILURE);
	}
	return (find_n_append(env, str));
}
