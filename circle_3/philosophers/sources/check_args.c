/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:21:31 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/28 12:49:57 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void check_args(int argc, char **argv, t_philo *philo)
{
	long long	temp;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (is_arg_digit(argv[i]) == 0)
			error_handler("error : arguments must be int");
		temp = ft_atoi(argv[i]);
		if (temp < 0 || temp > INT_MAX)
			error_handler("error : arguments must be int");
		else
			philo->philo_args[i - 1] = temp;
		i++;
	}
}