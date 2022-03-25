/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_and_join_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:44:59 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/16 12:35:31 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*compare_name_and_env(const char *name, char *env)
{
	while (*name && *env)
	{
		if (*name != *env)
			return (NULL);
		name++;
		env++;
	}
	if (*name == '\0' && *env == '=')
		return (env + 1);
	else
		return (NULL);
}

static char	*get_env_string(const char *name, t_list *our_env)
{
	t_list	*env_list;
	char	*env_string;
	char	*env_content;

	env_list = our_env;
	while (env_list)
	{
		env_string = env_list->line;
		env_content = compare_name_and_env(name, env_string);
		if (env_content)
			return (ft_strdup(env_content));
		env_list = env_list->next;
	}
	return (ft_strdup(""));
}

static int	get_env_name_len(char *name)
{
	int	i;

	i = 0;
	while (name[i] && ft_isalnum(name[i]))
		i++;
	return (i);
}

static int	join_env_string(char **str, char *env_string,
				int dollar_idx, int name_len)
{
	char	*fore;
	char	*back;
	char	*fore_and_env;
	char	*full_str;

	fore = ft_strdup(*str);
	fore[dollar_idx] = '\0';
	back = ft_strdup(*str + dollar_idx + name_len + 1);
	fore_and_env = ft_strjoin(fore, env_string);
	full_str = ft_strjoin(fore_and_env, back);
	ft_free_str(fore);
	ft_free_str(back);
	ft_free_str(fore_and_env);
	ft_free_str(*str);
	*str = full_str;
	return (0);
}

int	compare_and_join_env(char **str_to_expand, t_list *our_env,
							int i, int exit_status)
{
	int		name_len;
	char	*name;
	char	*env_string;

	if ((*str_to_expand)[i + 1] == '?')
	{
		env_string = ft_itoa(exit_status);
		if (env_string == NULL)
			return (MALLOC_ERR);
		join_env_string(str_to_expand, env_string, i, 1);
		return (!ft_free_str(env_string));
	}
	name_len = get_env_name_len(*str_to_expand + i + 1);
	if (name_len == 0)
		return (0);
	name = ft_substr(*str_to_expand, i + 1, name_len);
	if (name == NULL)
		return (MALLOC_ERR);
	env_string = get_env_string(name, our_env);
	if (env_string)
	{
		join_env_string(str_to_expand, env_string, i, name_len);
		ft_free_str(env_string);
	}
	return (!ft_free_str(name));
}
