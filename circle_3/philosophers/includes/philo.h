/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/11 17:18:18 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define N_OF_PHILO 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define MUST_EAT 4

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define FORK_L 5
# define FORK_R 6

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo_info	t_philo_info;

typedef struct s_philosopher
{
	int				number;
	pthread_t		thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*eat;
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
	pthread_mutex_t	eat;
	pthread_mutex_t	*fork_arr;
	int				philo_dead;
	int				is_must_eat_on;
	int				full_philo_cnt;
	int				done_eat;
}	t_philo_info;

long long	ft_atoi(char *str);
int			ft_isdigit(int c);

void		ft_putstr_fd(char *s, int fd);
int			check_args(int argc, char **argv, t_philo_info *philo);
int			error_handler(char *err);

int			init_philo(t_philo_info *vars);
void		*philo_do(void *data);
void		philo_take_fork(t_philosopher *philo);
void		philo_print(t_philosopher *philo, int state);

long long	get_time(void);
void		alt_sleep(long long time_to_sleep);

#endif
