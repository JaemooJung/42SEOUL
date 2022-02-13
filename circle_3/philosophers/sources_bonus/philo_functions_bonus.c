/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:01:31 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/02/13 20:15:04 by jaemoojung       ###   ########.fr       */
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
	printf("philo %d is dead? before take forks : %d\n", philo->num, philo->is_dead);
	philo_take_fork(philo);
	philo->time_fed = get_time();
	philo_print(philo, EAT);
	alt_sleep(philo->info->philo_args[T_EAT]);
	int drop1 = sem_post(philo->info->forks);
	int drop2 = sem_post(philo->info->forks);

	printf("%d dropped forks %d, %d \n", philo->num, drop1, drop2);
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

	pthread_create(&thread, NULL, check_philo, philo);
	while (philo->is_dead == 0)
	{
		printf("philo %d is dead? before eat : %d\n", philo->num, philo->is_dead);
		philo_eat(philo);
		printf("philo %d is dead? before sleep : %d\n", philo->num, philo->is_dead);
		philo_sleep(philo);
		printf("philo %d is dead? before think : %d\n", philo->num, philo->is_dead);
		philo_think(philo);
		printf("philo %d is dead? after one routine : %d\n", philo->num, philo->is_dead);
	}
}