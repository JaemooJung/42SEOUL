/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 15:00:11 by jaemjung         ###   ########.fr       */
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

	pthread_mutex_lock(&philosopher->info->print);
	printf("Hello! ");
	printf("I'm philo [%d], and ", philosopher->number);
	printf("this is tid %i\n", (int)tid);
	for (int i = 0; i < 5; i++) {
		printf("Working... [%d]\n", i);
	}
	pthread_mutex_unlock(&philosopher->info->print);

	return data;
}