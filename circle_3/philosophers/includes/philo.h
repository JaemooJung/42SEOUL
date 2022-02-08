/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/08 14:49:37 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define N_OF_PHILO 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define MUST_EAT 4

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef struct s_philo_info	t_philo_info;

typedef struct s_philosopher
{
	int				number;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	long long		time_fed;
	t_philo_info	*info;
	int				eat_cnt;
}	t_philosopher;

typedef struct s_philo_info
{
	int				philo_args[5];
	long long		time_start;
	t_philosopher	*philo_arr;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork_arr;
}	t_philo_info;

int			check_args(int argc, char **argv, t_philo_info *philo);
int			error_handler(char *err);

int			init_philosophers(t_philo_info *vars);
void		*philo_do(void *data);

long long	get_time(void);
void		alt_sleep(long long time_to_sleep);

#endif
