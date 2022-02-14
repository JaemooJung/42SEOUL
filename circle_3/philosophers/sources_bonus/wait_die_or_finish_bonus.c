/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_die_or_finish_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:39:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/14 15:50:02 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_philo(t_philo_b_info *info)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		kill(info->philo_arr[i].pid, SIGTERM);
		waitpid(info->philo_arr[i].pid, NULL, WNOHANG);
		i++;
	}
	sem_close(info->forks);
	sem_close(info->print);
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		temp = ft_itoa(i);
		sem_close(info->eat_dead_checks[i]);
		sem_unlink(temp);
		free(temp);
		i++;
	}
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("eat_check");
}

void	*wait_for_finish(void *data)
{
	t_philo_b_info	*info;
	int				i;

	info = (t_philo_b_info *)data;
	i = 0;
	while (i < info->philo_args[N_OF_PHILO])
	{
		sem_wait(info->eat_check);
		i++;
	}
	sem_wait(info->print);
	printf("philosophers are finished eating.\n");
	end_philo(info);
	exit(EXIT_FINISHED);
}

int	end_philo_dead(t_philo_b_info *info)
{
	end_philo(info);
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
