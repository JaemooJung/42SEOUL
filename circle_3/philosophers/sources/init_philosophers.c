/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:29:53 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 18:25:11 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_philo_info *info)
{
	int				i;
	int				j;
	int				pthread_check;

	//뮤텍스 생성
	pthread_mutex_init(&(info->print), NULL);
	j = 0;
	info->fork_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
						* info->philo_args[N_OF_PHILO]);
	if (info->fork_arr == NULL)
		return (error_handler("error: fork array malloc failed"));
	while (j < info->philo_args[N_OF_PHILO])
	{
		pthread_mutex_init(&(info->fork_arr[j]), NULL);
		j++;
	}

	//프로그램의 인자에서 N_OF_PHILO 땡겨와 배열 메모리 동적할당.
	info->philo_arr = (t_philosopher *)malloc(sizeof(t_philosopher)
						* info->philo_args[N_OF_PHILO]);
	if (info->philo_arr == NULL)
		return (error_handler("error: philosopher array malloc failed"));

	//스레드 생성
	i = 0;
	int n_of_philos = info->philo_args[N_OF_PHILO];
	while (i < info->philo_args[N_OF_PHILO])
	{
		info->philo_arr[i].number = i + 1;
		info->philo_arr[i].print = &(info->print);
		info->philo_arr[i].fork_left = &(info->fork_arr[i]);
		info->philo_arr[i].fork_right = &(info->fork_arr[((i + 1) % n_of_philos)]);
		

		pthread_check = pthread_create(&(info->philo_arr[i].thread),
					NULL, say_hello, &(info->philo_arr[i]));
		//pthread_join(info->philo_arr[i].thread, NULL);
		if (pthread_check != 0)
			return (error_handler("error: thread creation failed"));
		
		i++;
	}
	return (0);
}
