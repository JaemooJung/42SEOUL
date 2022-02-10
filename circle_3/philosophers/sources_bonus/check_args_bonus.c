/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:09:56 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/10 16:12:10 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_arg_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv, t_philo_b_info *info)
{
	long long	temp;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (is_arg_digit(argv[i]) == 0)
			return (error_handler("error : arguments must be int"));
		temp = ft_atoi(argv[i]);
		if (temp < 0 || temp > INT_MAX)
			return (error_handler("error : arguments must be int"));
		else
			info->philo_args[i - 1] = temp;
		i++;
	}
	if (info->philo_args[MUST_EAT])
		info->is_must_eat_on = 1;
	return (0);
}
