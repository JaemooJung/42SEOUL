/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:34:48 by hakim             #+#    #+#             */
/*   Updated: 2022/03/01 14:34:49 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mvs_env(char **chunk, t_list *env)
{
	(void)chunk;
	while (env != NULL)
	{
		if (ft_strchr(env->line, '=') != NULL)
			printf("%s\n", env->line);
		env = env->next;
	}
	return (SUCCESS);
}
