/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:23:22 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/06 13:18:02 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "error.h"
#include "utils.h"
#include "scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (new == NULL)
		error("object malloc failed");
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
		error("sphere malloc failed");
	sphere->center = center;
	sphere->radius = radius;
	sphere->radius2 = radius * radius;
	return (sphere);
}

t_cylinder	*cylinder(t_point3 center, double radius, t_vec3 dir, double height)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
		error("cylinder malloc failed");
	cylinder->center = center;
	cylinder->dir = vunit(dir);
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}

t_plane	*plane(t_point3 center, t_vec3 dir, double radius)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
		error("plane malloc failed");
	plane->center = center;
	plane->dir = vunit(dir);
	plane->radius = radius;
	return (plane);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color,
	double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		error("light malloc failed");
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
