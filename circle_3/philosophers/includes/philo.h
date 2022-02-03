/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:43:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/28 13:28:22 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct s_philo
{
	int			philo_args[5];
	pthread_t	*philo_threads;
}	t_philo;

void	check_args(int argc, char **argv, t_philo *philo);
void	error_handler(char *err);
void	*say_hello(void *data);

#endif
