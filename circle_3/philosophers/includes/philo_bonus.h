/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:50:55 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/11 17:35:03 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# define N_OF_PHILO 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define MUST_EAT 4

# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo_b_info
{
	int	philo_args[5];
	int	is_must_eat_on;

}	t_philo_b_info;

int			error_handler(char *err);
int			check_args(int argc, char **argv, t_philo_b_info *info);
long long	ft_atoi(char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
#endif