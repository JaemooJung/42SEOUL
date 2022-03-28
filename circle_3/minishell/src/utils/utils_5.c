/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:34 by hakim             #+#    #+#             */
/*   Updated: 2022/03/17 11:39:12 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	getlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++len;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		index;
	char	*result;

	len = getlen(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
		result[0] = '-';
	index = len - 1;
	while (n != 0)
	{
		result[index] = ft_abs(n % 10) + '0';
		n /= 10;
		--index;
	}
	return (result);
}

void	handle_parse_error(int err_code, int *exit_status)
{
	if (err_code == UNCLOSED_QUOTE)
	{
		*exit_status = 258;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("Unclosed quote\n", 2);
	}
	else if (err_code == PARSE_ERROR)
		*exit_status = err_code;
}
