/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:52:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/02/11 18:28:33 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo_b_info	info;
	pid_t			pid;

	if (5 > argc || argc > 6)
		return (error_handler("error : wrong usage"));
	memset(&info, 0, sizeof(t_philo_b_info));
	check_args(argc, argv, &info);
	pid = fork();
	for (int i = 0; i < 5; i++)
	{
		if (pid == 0)
		{
			printf("current process : %d\n", pid);
			printf("hello, child\n");
		}
		else
		{
			printf("current process : %d\n", pid);
		}
	}
	printf("last child process : %d\n", pid);
}
