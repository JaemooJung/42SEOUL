/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:37:03 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/28 14:30:10 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parser.h"

void	parse_line(t_parser *scene, char *line)
{
	char	**element;
	int		id;

	element = ft_split(line, ' ');
	id = check_identifier(element[0]);
	if (id == 0)
		;
	else if (id == 1)
		parse_ambient(scene, element);
	else if (id == 2)
		parse_camera(scene, element);
	else if (id == 3)
		parse_light(scene, element);
	else if (id == 4)
		parse_sphere(scene, element);
	else if (id == 5)
		parse_plane(scene, element);
	else if (id == 6)
		parse_cylinder(scene, element);
	else
		error_parser("wrong identifier\n", element[0]);
	free_pp(element);
}

void	parse(t_parser *scene, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_parser("failed to open file\n", file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		replace_space(line);
		parse_line(scene, line);
		free(line);
	}
	close(fd);
}

void	parser_init(t_parser *scene, char *file)
{
	check_extension(file);
	if (!get_size(file, 2))
		error_parser("camera doesn't exist\n", file);
	scene->s = get_size(file, 4);
	scene->p = get_size(file, 5);
	scene->cy = get_size(file, 6);
	scene->light.light_point = vec3(0, 0, 0);
	scene->light.ratio = 1;
	scene->light.rgb = color3(0, 0, 0);
	scene->spheres = \
	(t_parser_sphere *)malloc(sizeof(t_parser_sphere) * scene->s);
	scene->planes = \
	(t_parser_plane *)malloc(sizeof(t_parser_plane) * scene->p);
	scene->cylinders = \
	(t_parser_cylinder *)malloc(sizeof(t_parser_cylinder) * scene->cy);
	parse(scene, file);
}
