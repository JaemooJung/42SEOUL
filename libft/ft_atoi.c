/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:14:06 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 19:02:30 by jaemjung         ###   ########.fr       */
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

int			ft_atoi(char *str)
{
	int	sign;
	int int_ret;
	int i;

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
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		int_ret = int_ret * 10;
		int_ret = int_ret + (str[i] - '0');
		i++;
	}
	return (int_ret * sign);
}
