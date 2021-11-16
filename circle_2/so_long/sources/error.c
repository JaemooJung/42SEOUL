/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:25:26 by jaemjung          #+#    #+#             */
/*   Updated: 2021/11/16 17:25:38 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handler(char *error_message)
{
	if (!error_message)
	{
		printf("Error\n%s\n", strerror(errno));
		exit(errno);
	}
	else
	{
		printf("Error\n%s\n", error_message);
		exit(1);
	}
}
