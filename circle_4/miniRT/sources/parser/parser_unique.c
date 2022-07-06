/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:10:04 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/27 20:04:16 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_ambient(t_parser *scene, char **element)
{
	static int	exist;

	if (exist)
		error_parser("defined twice\n", "abient light");
	exist = 1;
	if (count_element(element) != 3)
		error_parser("wrong args\n", "abient light");
	scene->ambient_light.ratio = \
	parse_double_range(element[1], 0.0, 1.0);
	scene->ambient_light.rgb = \
	parse_coordinate_range(element[2], 0.0, 255.0, 0);
}

void	parse_camera(t_parser *scene, char **element)
{
	static int	exist;

	if (exist)
		error_parser("defined twice\n", "camera");
	exist = 1;
	if (count_element(element) != 4)
		error_parser("wrong args\n", "camera");
	scene->camera.view_point = parse_coordinate(element[1]);
	scene->camera.orientation = \
	parse_coordinate_range(element[2], -1.0, 1.0, 1);
	scene->camera.fov = parse_double_range(element[3], 0.0, 180.0);
}

void	parse_light(t_parser *scene, char **element)
{
	static int	exist;

	if (exist)
		error_parser("defined twice\n", "light");
	exist = 1;
	if (count_element(element) != 4)
		error_parser("wrong args\n", "light");
	scene->light.light_point = parse_coordinate(element[1]);
	scene->light.ratio = parse_double_range(element[2], 0.0, 1.0);
	scene->light.rgb = parse_coordinate_range(element[3], 0.0, 255.0, 0);
}
