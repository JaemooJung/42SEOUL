/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:26 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/10 15:20:00 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eat(t_philo_info *info)
{
	int	i;

	i = 0;
	while (info->is_must_eat_on && i < info->philo_args[N_OF_PHILO]
		&& info->philo_arr[i].eat_cnt >= info->philo_args[MUST_EAT])
		i++;
	if (i == info->philo_args[N_OF_PHILO])
		info->done_eat = 1;
	return (0);
}

int	check_dead(t_philo_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_args[N_OF_PHILO] && (info->philo_dead == 0))
	{
		pthread_mutex_lock(&(info->eat));
		if (get_time() - info->philo_arr[i].time_fed
			> info->philo_args[T_DIE])
		{
			philo_print(&(info->philo_arr[i]), DEAD);
			info->philo_dead = 1;
		}
		pthread_mutex_unlock(&(info->eat));
		i++;
	}
	return (0);
}

int	check_philo(t_philo_info *info)
{
	while (1)
	{
		check_dead(info);
		if (info->philo_dead == 1)
			break ;
		check_eat(info);
		if (info->done_eat == 1)
		{
			pthread_mutex_lock(&(info->print));
			printf("All philosophers are done eating.\n");
			break ;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_info	info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	ft_bzero(&info, sizeof(t_philo_info));
	check_args(argc, argv, &info);
	init_philo(&info);
	check_philo(&info);
}
