/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:10:51 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/27 17:58:14 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_sphere(t_parser *scene, char **element)
{
	static int	i;

	if (count_element(element) != 4)
		error_parser("wrong args\n", "sphere");
	scene->spheres[i].center = parse_coordinate(element[1]);
	scene->spheres[i].diameter = parse_double(element[2]);
	scene->spheres[i].rgb = \
	parse_coordinate_range(element[3], 0.0, 255.0, 0);
	i++;
}

void	parse_plane(t_parser *scene, char **element)
{
	static int	i;

	if (count_element(element) != 4)
		error_parser("wrong args\n", "plane");
	scene->planes[i].coord = parse_coordinate(element[1]);
	scene->planes[i].orientation = \
	parse_coordinate_range(element[2], -1.0, 1.0, 1);
	scene->planes[i].rgb = \
	parse_coordinate_range(element[3], 0.0, 255.0, 0);
	i++;
}

void	parse_cylinder(t_parser *scene, char **element)
{
	static int	i;

	if (count_element(element) != 6)
		error_parser("wrong args\n", "cylinder");
	scene->cylinders[i].coord = parse_coordinate(element[1]);
	scene->cylinders[i].orientation = \
	parse_coordinate_range(element[2], -1.0, 1.0, 1);
	scene->cylinders[i].diameter = parse_double(element[3]);
	scene->cylinders[i].height = parse_double(element[4]);
	scene->cylinders[i].rgb = \
	parse_coordinate_range(element[5], 0.0, 255.0, 0);
	i++;
}
