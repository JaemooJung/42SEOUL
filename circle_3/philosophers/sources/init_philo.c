/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:29:53 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/14 11:58:07 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_philo_info *info)
{
	int	i;

	i = 0;
	info->fork_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->philo_args[N_OF_PHILO]);
	if (info->fork_arr == NULL)
		return (error_handler("error: fork array malloc failed"));
	while (i < info->philo_args[N_OF_PHILO])
	{
		pthread_mutex_init(&(info->fork_arr[i]), NULL);
		i++;
	}
	return (0);
}

int	init_eat_check(t_philo_info *info)
{
	int	i;

	i = 0;
	info->eats = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->philo_args[N_OF_PHILO]);
	if (info->eats == NULL)
		return (error_handler("error: eat array malloc failed"));
	while (i < info->philo_args[N_OF_PHILO])
	{
		pthread_mutex_init(&(info->eats[i]), NULL);
		i++;
	}
	return (0);
}

int	init_philosophers(t_philo_info *info)
{
	int	i;

	info->philo_arr = (t_philosopher *)malloc(sizeof(t_philosopher)
			* info->philo_args[N_OF_PHILO]);
	if (info->philo_arr == NULL)
		return (error_handler("error: philosopher array malloc failed"));
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		info->philo_arr[i].number = i + 1;
		info->philo_arr[i].print = &(info->print);
		info->philo_arr[i].eat = &(info->eats[i]);
		info->philo_arr[i].fork_l = &(info->fork_arr[i]);
		info->philo_arr[i].fork_r = &(info->fork_arr[((i + 1)
					% info->philo_args[N_OF_PHILO])]);
		info->philo_arr[i].time_fed = get_time();
		info->philo_arr[i].info = info;
		info->philo_arr[i].eat_cnt = 0;
		pthread_create(&(info->philo_arr[i].thread), NULL, philo_do,
			&(info->philo_arr[i]));
		pthread_detach(info->philo_arr[i].thread);
		i++;
		usleep(10);
	}
	return (0);
}

int	init_philo(t_philo_info *info)
{
	pthread_mutex_init(&(info->print), NULL);
	if (init_eat_check(info))
		return (1);
	if (init_fork(info))
		return (1);
	info->time_start = get_time();
	if (init_philosophers(info))
		return (1);
	return (0);
}
