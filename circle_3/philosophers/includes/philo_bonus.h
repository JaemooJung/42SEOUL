/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:50:55 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/13 20:17:08 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# define N_OF_PHILO 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define MUST_EAT 4

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define FORK 5

# define EXIT_FINISHED 42
# define EXIT_DEAD 43

# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_philo_b_info	t_philo_b_info;

typedef struct s_philo_b
{
	pid_t 			pid;
	int				num;
	long long		time_fed;
	int				eat_cnt;
	int				is_dead;
	t_philo_b_info	*info;
}	t_philo_b;

typedef struct s_philo_b_info
{
	int			philo_args[5];
	long long	time_start;
	int			is_must_eat_on;
	t_philo_b	*philo_arr;
	sem_t		*forks;
	sem_t		*print;
}	t_philo_b_info;

int			error_handler(char *err);
int			check_args(int argc, char **argv, t_philo_b_info *info);
long long	ft_atoi(char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		alt_sleep(long long time_to_sleep);
long long	get_time(void);
void		philo_print(t_philo_b *philo, int state);

void		init_philo(t_philo_b_info *info);
void		philo_do(t_philo_b *philo);
void		*check_philo(void *data);
#endif