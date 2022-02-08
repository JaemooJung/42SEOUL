/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:26 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/08 15:40:09 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_philo(t_philo_info *info)
{
	int	done_eat;
	int	idx;

	idx = 0;
	done_eat = 0;
	while (idx < info->philo_args[N_OF_PHILO])
	{
	// 	if (get_time() - info->philo_arr[idx].time_fed > info->philo_args[T_DIE])
	// 	{
	// 		pthread_mutex_lock(info->philo_arr[idx].print);
	// 		printf("%lld %d died", get_time() - info->time_start,
	// 			info->philo_arr[idx].number);
	// 	}
	// 	idx++;
	// 	if (idx == info->philo_args[N_OF_PHILO])
	// 		idx = 0;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_philo_info info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	ft_bzero(&info, sizeof(t_philo_info));
	check_args(argc, argv, &info);
	init_philosophers(&info);
	check_philo(&info);

	system("leaks philo > leaks_result_temp; cat leaks_result_temp && rm -rf leaks_result_temp");
}