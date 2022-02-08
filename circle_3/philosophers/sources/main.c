/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:26 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/08 17:15:25 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_philo(t_philo_info *info)
{
	while (1)
	{
		info->philo_args[MUST_EAT]++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_philo_info info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	ft_bzero(&info, sizeof(t_philo_info));
	check_args(argc, argv, &info);
	init_philosophers(&info);
	check_philo(&info);

	system("leaks philo > leaks_result_temp; cat leaks_result_temp && rm -rf leaks_result_temp");
}