/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:38:26 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/28 13:42:39 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philo philo;
	pthread_t test;

	if (5 > argc || argc > 6)
		error_handler("error : wrong usage");
	ft_bzero(&philo, sizeof(philo));
	check_args(argc, argv, &philo);
	//TODO : Delete this code later
	for (int i = 0; i < argc - 1; i++)
	{
		printf("%d ", philo.philo_args[i]);
		printf("\n");
	}
	//_____________________
	pthread_create(&test, NULL, say_hello, NULL);
	pthread_join(test, NULL); //조인을 쓰면 메인함수가 종료
}