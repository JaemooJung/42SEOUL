/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:53:50 by hakim             #+#    #+#             */
/*   Updated: 2022/03/08 23:40:14 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*env_free_str(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

t_list	*envp_to_ours(char **envp)
{
	t_list	*head;
	t_list	*cur;
	char	*line;
	int		index;

	index = 0;
	line = ft_strdup(envp[index++]);
	if (line == NULL)
		return (NULL);
	head = ft_lstnew(line);
	if (head == NULL)
		return (env_free_str(line));
	cur = head;
	while (envp[index] != NULL)
	{
		line = ft_strdup(envp[index++]);
		if (line == NULL)
			return (ft_free_lst(head));
		ft_lstadd_back(&head, ft_lstnew(line));
		cur = cur->next;
		if (cur == NULL)
			return (ft_free_lst(head));
	}
	return (head);
}
// when return NULL, should minishell_exit with error message??

char	*get_value(t_list *env, char *key)
{
	size_t	len;

	while (env != NULL)
	{
		len = ft_strlen(key);
		if (ft_strncmp(env->line, key, len) == 0 && env->line[len] == '=')
			return (env->line + len + 1);
		env = env->next;
	}
	return (NULL);
}

char	**to_vector(t_list *env)
{
	size_t	size;
	size_t	index;
	char	**envp;

	size = ft_lstsize(env);
	envp = malloc(sizeof(char *) * (size + 1));
	if (envp == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		envp[index++] = env->line;
		env = env->next;
	}
	envp[size] = NULL;
	return (envp);
}

int	add_shlvl(t_list *env)
{
	int		shlvl;
	char	*newlvl;
	char	*temp;

	while (env != NULL)
	{
		if (ft_strncmp(env->line, "SHLVL=", 6) == 0)
			break ;
		env = env->next;
	}
	if (env == NULL)
		return (SUCCESS);
	shlvl = ft_atoi(env->line + 6);
	temp = ft_itoa(++shlvl);
	if (temp == NULL)
		return (FAILURE);
	newlvl = ft_strjoin("SHLVL=", temp);
	if (newlvl == NULL)
		return (ft_free_str(temp));
	ft_free_str(temp);
	ft_free_str(env->line);
	env->line = newlvl;
	return (SUCCESS);
}
