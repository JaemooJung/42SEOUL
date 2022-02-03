/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 18:26:49 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *say_hello(void *data)
{
	pthread_t		tid;
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	usleep(100);
	tid = pthread_self();

	pthread_mutex_lock(philosopher->fork_left);
	printf("Philo No %d took the left fork\n", philosopher->number);
	pthread_mutex_lock(philosopher->fork_right);
	printf("Philo No %d took the right fork\n", philosopher->number);
	printf("Hello! ");
	printf("I'm philo [%d], and ", philosopher->number);
	printf("this is tid %i\n", (int)tid);
	for (int i = 0; i < 5; i++) {
		printf("Philo[%d] Working... [%d]\n", philosopher->number, i);
		sleep(1);
	}
	pthread_mutex_unlock(philosopher->fork_left);
	printf("Philo No %d dropped the left fork\n", philosopher->number);
	pthread_mutex_unlock(philosopher->fork_right);
	printf("Philo No %d dropped the right fork\n", philosopher->number);

	return data;
}