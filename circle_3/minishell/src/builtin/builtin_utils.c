/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:47:52 by hakim             #+#    #+#             */
/*   Updated: 2022/03/14 14:28:59 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_init(int (*func[])(char **, t_list *))
{
	func[CD] = mvs_cd;
	func[M_ECHO] = mvs_echo;
	func[ENV] = mvs_env;
	func[EXIT] = mvs_exit;
	func[EXPORT] = mvs_export;
	func[PWD] = mvs_pwd;
	func[UNSET] = mvs_unset;
}

int	classify_builtin(char *str)
{
	if (ft_strncmp(str, "cd", 3) == 0)
		return (CD);
	else if (ft_strncmp(str, "echo", 5) == 0)
		return (M_ECHO);
	else if (ft_strncmp(str, "env", 4) == 0)
		return (ENV);
	else if (ft_strncmp(str, "exit", 5) == 0)
		return (EXIT);
	else if (ft_strncmp(str, "export", 7) == 0)
		return (EXPORT);
	else if (ft_strncmp(str, "pwd", 4) == 0)
		return (PWD);
	else if (ft_strncmp(str, "unset", 6) == 0)
		return (UNSET);
	else
		return (NONE);
}
