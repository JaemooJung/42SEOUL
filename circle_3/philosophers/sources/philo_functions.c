/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/09 15:46:51 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philosopher *philo)
{	
	philo_take_fork(philo);
	philo->eat_cnt++;
	philo_print(philo, EAT);
	philo->time_fed = get_time();
	alt_sleep(philo->info->philo_args[T_EAT]);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
	return (0);
}

int philo_sleep(t_philosopher *philo)
{
	philo_print(philo, SLEEP);
	alt_sleep(philo->info->philo_args[T_SLEEP]);
	return (0);
}

int philo_think(t_philosopher *philo)
{
	philo_print(philo, THINK);
	usleep(10);
	return (0);
}

void	*philo_do(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *)data;
	while (philo->info->philo_dead == 0 && philo->info->done_eat == 0)
	{
		philo_eat(philo);
		if (philo->info->done_eat == 1)
			break;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
