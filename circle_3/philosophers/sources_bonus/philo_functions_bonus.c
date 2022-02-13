/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:01:31 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/02/13 23:17:18 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_take_fork(t_philo_b *philo)
{
	sem_wait(philo->info->forks);
	philo_print(philo, FORK);
	sem_wait(philo->info->forks);
	philo_print(philo, FORK);
}

void	philo_eat(t_philo_b *philo)
{
	philo_take_fork(philo);
	philo->time_fed = get_time();
	philo_print(philo, EAT);
	alt_sleep(philo->info->philo_args[T_EAT]);
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
	philo->eat_cnt++;
}

void	philo_sleep(t_philo_b *philo)
{
	philo_print(philo, SLEEP);
	alt_sleep(philo->info->philo_args[T_SLEEP]);
}

void	philo_think(t_philo_b *philo)
{
	philo_print(philo, THINK);
	usleep(200);
}

void	philo_do(t_philo_b *philo)
{
	pthread_t	thread;

	if (philo->info->is_must_eat_on)
	{
		sem_wait(philo->info->eat_check);
		printf("eat locked from %d\n", philo->num);
	}
	pthread_create(&thread, NULL, check_philo, philo);
	while (philo->is_dead == 0)
	{
		philo_eat(philo);
		if (philo->info->is_must_eat_on
			&& philo->eat_cnt >= philo->info->philo_args[MUST_EAT]
			&& philo->if_finished_eating == 0)
		{
			printf("current eat count : %d\n", philo->eat_cnt);
			philo->if_finished_eating = 1;
			sem_post(philo->info->eat_check);
		}
		philo_sleep(philo);
		philo_think(philo);
	}
}