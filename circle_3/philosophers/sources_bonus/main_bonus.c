/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:52:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/14 08:16:36 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*wait_for_finish(void *data)
{
	t_philo_b_info	*info;
	int i;

	info = (t_philo_b_info *)data;
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		sem_wait(info->eat_check);
		printf("one philo doneeeeeeeeeeeeeeee\n");
		i++;
	}
	sem_wait(info->print);
	printf("All philosophers are finished eating\n");
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		kill(info->philo_arr[i].pid, SIGTERM);
		waitpid(info->philo_arr[i].pid, NULL, WNOHANG);
		i++;
	}
	sem_close(info->forks);
	sem_close(info->print);
	sem_close(info->eat_check);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat_check");
	while (1)
		;
	exit(EXIT_FINISHED);
}

int	end_philo_dead(t_philo_b_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		kill(info->philo_arr[i].pid, SIGTERM);
		waitpid(info->philo_arr[i].pid, NULL, WNOHANG);
		i++;
	}
	sem_close(info->forks);
	sem_close(info->print);
	sem_close(info->eat_check);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat_check");
	while (1)
		;
	exit(EXIT_DEAD);
}

int	wait_die_or_finish(t_philo_b_info *info)
{
	pid_t		exited_pid;
	int			status;
	pthread_t	eat_check_thread;

	if (info->is_must_eat_on)
	{
		pthread_create(&eat_check_thread, NULL, wait_for_finish, info);
		pthread_detach(eat_check_thread);
	}
	exited_pid = waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == EXIT_DEAD)
			end_philo_dead(info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_b_info	info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	memset(&info, 0, sizeof(t_philo_b_info));
	check_args(argc, argv, &info);
	init_philo(&info);
	wait_die_or_finish(&info);
}
