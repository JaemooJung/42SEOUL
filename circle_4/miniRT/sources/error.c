/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:31:11 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/03 19:43:25 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error(const char *message)
{
	printf("Error:\n%s\n", message);
	exit(1);
}

void	error_parser(char *msg, char *arg)
{
	printf("Error\n");
	if (arg)
		printf("\'%s\': %s", arg, msg);
	else
		printf("%s", msg);
	exit(1);
}
