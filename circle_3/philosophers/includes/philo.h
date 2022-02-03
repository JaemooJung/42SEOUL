/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 15:02:00 by jaemjung         ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct s_philo_info	t_philo_info;

typedef struct s_philosopher
{
	int					number;
	pthread_t			thread;
	//왼쪽포크
	//오른쪽포크
	struct s_philo_info	*info;
}	t_philosopher;

typedef struct s_philo_info
{
	int				philo_args[5];
	pthread_mutex_t	print;
	t_philosopher	*philo_arr;
}	t_philo_info;

int		check_args(int argc, char **argv, t_philo_info *philo);
int		error_handler(char *err);
void	*say_hello(void *data);
int		init_philosophers(t_philo_info *vars);

#endif
