/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:14:54 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/02/14 15:38:42 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_print(t_philo_b *philo, int state)
{
	sem_wait(philo->info->print);
	printf("%lld %d ", get_time() - philo->info->time_start, philo->num);
	if (state == EAT)
	{
		printf("is eating");
		if (philo->info->is_must_eat_on)
			printf(" - have eaten %d times", philo->eat_cnt);
		printf("\n");
	}
	else if (state == SLEEP)
		printf("is sleeping\n");
	else if (state == THINK)
		printf("is thinking\n");
	else if (state == FORK)
		printf("has taken a fork\n");
	else if (state == DEAD)
	{
		printf("died\n");
		return ;
	}
	sem_post(philo->info->print);
}
