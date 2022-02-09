/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:55:59 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/02/09 13:31:14 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philosopher *philo, int state)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d ", get_time() - philo->info->time_start, philo->number);
	if (state == EAT)
	{
		printf("is eating");
		if (philo->info->is_must_eat_on)
			printf(" - have eaten %d times", philo->eat_cnt);
		printf("\n");
	}
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	else if (state == FORK_L)
		printf("has taken fork on the left\n");
	else if (state == FORK_R)
		printf("has taken fork on the right\n");
	else if (state == DEAD)
		printf("died\n");
	pthread_mutex_unlock(philo->print);
}

void	philo_take_fork(t_philosopher *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_l);
		philo_print(philo, FORK_L);
		pthread_mutex_lock(philo->fork_r);
		philo_print(philo, FORK_R);
	}
	else
	{
		pthread_mutex_lock(philo->fork_r);
		philo_print(philo, FORK_R);
		pthread_mutex_lock(philo->fork_l);
		philo_print(philo, FORK_L);
	}
}