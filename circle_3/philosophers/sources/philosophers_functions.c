/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/07 18:39:02 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(void)
{
	struct timeval time;
	long long	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

int	philo_eat(t_philosopher *philo)
{
	
	pthread_mutex_lock(philo->print);
	philo->time_fed = get_time();
	printf("%lld %d is eating\n", philo->time_fed - philo->info->time_start,
			philo->number);
	usleep(200000);
	pthread_mutex_unlock(philo->print);
	return (0);
}

void	*say_hello(void *data)
{
	pthread_t		tid;
	t_philosopher	*philosopher;
	long long		start_time;

	philosopher = (t_philosopher *)data;
	tid = pthread_self();
	if (philosopher->number % 2 == 0)
		usleep(10000);
	pthread_mutex_lock(philosopher->fork_left);
	printf("Philo No %d took the left fork\n", philosopher->number);
	pthread_mutex_lock(philosopher->fork_right);
	printf("Philo No %d took the right fork\n", philosopher->number);
	printf("Hello! ");
	printf("I'm philo [%d], and ", philosopher->number);
	printf("this is tid %i\n", (int)tid);
	start_time = get_time();
	for (int i = 0; i < 5; i++) {
		printf("[%lld] philo No[%d] did his job of [%d]\n", get_time() - start_time, philosopher->number, i);
		usleep(100000);
	}
	pthread_mutex_unlock(philosopher->fork_right);
	printf("Philo No %d dropped the right fork\n", philosopher->number);
	pthread_mutex_unlock(philosopher->fork_left);
	printf("Philo No %d dropped the left fork\n", philosopher->number);
	return data;
}

void	*philo_do(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		if (philo->number % 2 == 0)
			usleep(10000);
		pthread_mutex_lock(philo->fork_left);
		printf("%lld %d took the left fork\n", get_time() - philo->info->time_start
				,philo->number);
		pthread_mutex_lock(philo->fork_right);
		printf("%lld %d took the right fork\n", get_time() - philo->info->time_start,
				philo->number);
		philo_eat(philo);
		pthread_mutex_unlock(philo->fork_right);
		printf("%lld %d dropped the right fork\n", get_time() - philo->info->time_start,
				philo->number);
		pthread_mutex_unlock(philo->fork_left);
		printf("%lld %d dropped the left fork\n", get_time() - philo->info->time_start,
		philo->number);
		usleep(200000);
	}
	return ((void *)philo);
}