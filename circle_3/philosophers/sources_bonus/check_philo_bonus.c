/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:51:47 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/02/13 23:14:20 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_philo(void *data)
{
	t_philo_b	*philo;

	philo = (t_philo_b *)data;
	while (1)
	{
		if (get_time() - philo->time_fed > philo->info->philo_args[T_DIE])
		{
			philo_print(philo, DEAD);
			exit(EXIT_DEAD);
		}
	}
}