/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/08 15:28:44 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	philo_eat(t_philosopher *philo)
{	
	pthread_mutex_lock(philo->print);
	printf("%lld %d is eating\n", get_time() - philo->info->time_start,
			philo->number);
	pthread_mutex_unlock(philo->print);
	alt_sleep(philo->info->philo_args[T_EAT]);
	philo->time_fed = get_time();
	philo->eat_cnt++;
	return (0);
}

int philo_sleep(t_philosopher *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is sleeping\n", get_time() - philo->info->time_start,
			philo->number);
	pthread_mutex_unlock(philo->print);
	alt_sleep(philo->info->philo_args[T_SLEEP]);
	return (0);
}

int philo_think(t_philosopher *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is thinking\n", get_time() - philo->info->time_start,
			philo->number);
	pthread_mutex_unlock(philo->print);
	alt_sleep(100);
	return (0);
}

void	*philo_do(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		if (philo->number % 2 == 0)
			alt_sleep(100);
		pthread_mutex_lock(philo->fork_l);
		pthread_mutex_lock(philo->print);
		printf("%lld %d has taken the left fork\n", get_time() -
					philo->info->time_start, philo->number);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->fork_r);
		pthread_mutex_lock(philo->print);
		printf("%lld %d has taken the right fork\n", get_time() -
					philo->info->time_start, philo->number);
		pthread_mutex_unlock(philo->print);
		philo_eat(philo);
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_unlock(philo->fork_l);
		philo_sleep(philo);
		philo_think(philo);
	}
	return ((void *)philo);
}
