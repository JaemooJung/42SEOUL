/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:40:25 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/27 20:09:01 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

double	parse_double(char *str)
{
	char	**splitted;
	double	res;
	int		c;

	splitted = ft_split(str, '.');
	c = count_element(splitted);
	res = 0;
	if (c == 1)
		res = (double)(ft_atoi(check_number(splitted[0])));
	else if (c == 2)
	{
		res = (double)(ft_atoi(check_number(splitted[1])));
		if (res < 0)
			error_parser("double negative decimals\n", str);
		res /= pow(10, ft_strlen(splitted[1]));
		res += (double)ft_atoi(check_number(splitted[0]));
		if (splitted[0][0] == '-' && res > 0)
			res *= -1;
	}
	else
		error_parser("fail to parse double\n", str);
	free_pp(splitted);
	return (res);
}

double	parse_double_range(char *str, double from, double to)
{
	double	res;

	res = parse_double(str);
	if (res < from || res > to)
		error_parser("double out of defined range\n", str);
	return (res);
}

t_vec3	parse_coordinate(char *str)
{
	char	**splitted;
	t_vec3	coordinate;

	splitted = ft_split(str, ',');
	if (count_element(splitted) != 3)
		error_parser("fail to parse coord\n", str);
	coordinate.x = parse_double(splitted[0]);
	coordinate.y = parse_double(splitted[1]);
	coordinate.z = parse_double(splitted[2]);
	free_pp(splitted);
	return (coordinate);
}

t_vec3	parse_coordinate_range(char *str, double from, double to, int norm)
{
	t_vec3	v;

	v = parse_coordinate(str);
	if (v.x < from || v.x > to || \
	v.y < from || v.y > to || v.z < from || v.z > to)
		error_parser("coord out of defined range\n", str);
	if (norm)
		return (vunit(v));
	return (v);
}
