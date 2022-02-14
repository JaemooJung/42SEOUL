/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/14 12:01:06 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philosopher *philo)
{	
	philo_take_fork(philo);
	pthread_mutex_lock(philo->eat);
	philo->eat_cnt++;
	philo_print(philo, EAT);
	philo->time_fed = get_time();
	pthread_mutex_unlock(philo->eat);
	alt_sleep(philo->info->philo_args[T_EAT]);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
	return (0);
}

int	philo_sleep(t_philosopher *philo)
{
	philo_print(philo, SLEEP);
	alt_sleep(philo->info->philo_args[T_SLEEP]);
	return (0);
}

int	philo_think(t_philosopher *philo)
{
	philo_print(philo, THINK);
	usleep(200);
	return (0);
}

void	*philo_do(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (philo->info->philo_dead == 0 && philo->info->done_eat == 0)
	{
		philo_eat(philo);
		if (philo->info->philo_dead == 1)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
