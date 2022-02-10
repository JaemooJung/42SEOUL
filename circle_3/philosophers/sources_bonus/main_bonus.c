/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:52:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/10 18:30:58 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_b_info	info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	ft_bzero(&info, sizeof(t_philo_b_info));
	check_args(argc, argv, &info);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", info.philo_args[i]);
	}
	printf("\n");
}
