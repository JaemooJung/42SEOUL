/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:26 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/03 14:26:20 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philo_info info;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	ft_bzero(&info, sizeof(t_philo_info));
	check_args(argc, argv, &info);
	//TODO : Delete this code later
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d ", info.philo_args[i]);
		printf("\n");
	}
	//_____________________
	init_philosophers(&info);
	sleep(1);
	system("leaks philo > leaks_result_temp; cat leaks_result_temp && rm -rf leaks_result_temp");
}