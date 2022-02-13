/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:47:50 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/02/13 23:32:44 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*init_sem(t_philo_b_info *info, char *name, unsigned int val)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, val);
	if (sem == SEM_FAILED)
	{
		sem_unlink(name);
		sem = sem_open(name, O_CREAT | O_EXCL, 0644, val);
	}
	if (info->forks == SEM_FAILED)
		error_handler("error : sem_open failed");
	return (sem);
}

void	init_semaphores(t_philo_b_info *info)
{
	info->forks = init_sem(info, "fork", info->philo_args[N_OF_PHILO]);
	info->print = init_sem(info, "print", 1);
	info->eat_check = init_sem(info, "eat_check", info->philo_args[N_OF_PHILO]);
}

void	init_philosophers(t_philo_b_info *info)
{
	int i;

	info->philo_arr = (t_philo_b *)malloc(sizeof(t_philo_b) *
		info->philo_args[N_OF_PHILO]);
	if (!info->philo_arr)
		error_handler("error : philo arr malloc failed");
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		info->philo_arr[i].num = i + 1;
		info->philo_arr[i].eat_cnt = 0;
		info->philo_arr[i].if_finished_eating = 0;
		info->philo_arr[i].is_dead = 0;
		info->philo_arr[i].info = info;
		i++;
	}
}

void	fork_philosophers(t_philo_b_info *info)
{
	int	i;

	info->time_start = get_time();
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		info->philo_arr[i].time_fed = info->time_start;
		info->philo_arr[i].pid = fork();
		if (info->philo_arr[i].pid == 0)
			philo_do(&info->philo_arr[i]);
		else if (info->philo_arr[i].pid < 0)
			error_handler("error : philosopher fork failed");
		i++;
		printf("process %d created\n", i);
		usleep(10);
	}
	usleep(100000);
	info->finished_fork = 1;
}

void	init_philo(t_philo_b_info *info)
{
	init_semaphores(info);
	init_philosophers(info);
	fork_philosophers(info);
}