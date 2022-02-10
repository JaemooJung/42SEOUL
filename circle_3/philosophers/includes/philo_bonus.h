/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:50:55 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/10 16:19:01 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# define N_OF_PHILO 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define MUST_EAT 4

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_philo_b_info
{
	int	philo_args[5];
	int	is_must_eat_on;

}	t_philo_b_info;

int	error_handler(char *err);
int	check_args(int argc, char **argv, t_philo_b_info *info);


#endif