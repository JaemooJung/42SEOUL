/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:53:27 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 13:35:43 by jaemjung         ###   ########.fr       */
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
	printf("Hello! ");
	printf("I'm philo [%d], and ", philosopher->number);
	printf("this is tid %i\n", (int)tid);
	return data;
}