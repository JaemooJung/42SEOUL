/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:52:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/14 11:41:50 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_b_info	info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	memset(&info, 0, sizeof(t_philo_b_info));
	check_args(argc, argv, &info);
	init_philo(&info);
	wait_die_or_finish(&info);
}
