/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:05:57 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/27 17:58:27 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_identifier(char *id)
{
	if (!id)
		return (0);
	else if (!ft_strncmp(id, "A", 2))
		return (1);
	else if (!ft_strncmp(id, "C", 2))
		return (2);
	else if (!ft_strncmp(id, "L", 2))
		return (3);
	else if (!ft_strncmp(id, "sp", 3))
		return (4);
	else if (!ft_strncmp(id, "pl", 3))
		return (5);
	else if (!ft_strncmp(id, "cy", 3))
		return (6);
	else
		return (-1);
}

void	check_extension(char *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == '.')
			j = i;
		i++;
	}
	if (file[j++] != '.')
		error_parser("wrong extension\n", file);
	if (file[j++] != 'r')
		error_parser("wrong extension\n", file);
	if (file[j++] != 't')
		error_parser("wrong extension\n", file);
	if (file[j])
		error_parser("wrong extension\n", file);
}

char	*check_number(char *num)
{
	int			i;
	int			neg;
	long long	sum;

	i = 0;
	neg = 0;
	sum = 0;
	while (num[i])
	{
		if (i == 0 && (num[i] == '-' || num[i] == '+'))
		{
			if (num[i++] == '-')
				neg = 1;
			if (!num[i])
				error_parser("fail to parse number\n", num);
			continue ;
		}
		if (!ft_isdigit(num[i]))
			error_parser("not a number\n", num);
		sum = sum * 10 + (num[i] - '0');
		if (sum > (long long)(2147483647) + neg)
			error_parser("number overflow\n", num);
		i++;
	}
	return (num);
}
