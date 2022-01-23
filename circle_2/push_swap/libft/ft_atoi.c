/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:14:06 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/23 11:34:13 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	is_white_space(char c)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if ("\n\t\v\f\r "[i] == c)
			return (1);
		i++;
	}
	return (0);
}

long long	ft_atoi(char *str)
{
	long long	sign;
	long long	int_ret;
	int			i;

	sign = 1;
	i = 0;
	int_ret = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		else if (str[i] == '\0')
			return (2147483648);
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		int_ret = int_ret * 10;
		int_ret = int_ret + (str[i] - '0');
		i++;
	}
	return (int_ret * sign);
}
