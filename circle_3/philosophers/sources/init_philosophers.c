/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:29:53 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 13:35:45 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_philo_info *info)
{
	int	i;
	int	pthread_check;

	//들어온 인자에서 필로소퍼 숫자 땡겨와 배열 메모리 동적할당.
	info->philo_arr = (t_philosopher *)malloc(sizeof(t_philosopher)
						* info->philo_args[N_OF_PHILO]);
	if (info->philo_arr == NULL)
		return (error_handler("error: philosopher array malloc failed"));
	//스레드 생성
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		info->philo_arr[i].number = i;
		
		//포크 및 번호 설정해준 후 스레드 시작
		pthread_check = pthread_create(&(info->philo_arr[i].thread),
					NULL, say_hello, &(info->philo_arr[i]));
		if (pthread_check != 0)
			return (error_handler("error: thread creation failed"));
		
		i++;
	}
	return (0);
}
