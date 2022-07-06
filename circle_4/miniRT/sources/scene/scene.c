/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:23:29 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/04 03:00:11 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parser.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_vec3	cam_set_vup(t_vec3 dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (vec3(0, dir.y, EPSILON));
	else
		return (vec3(0, 1, 0));
}

/*
	camera
	focal length is decided by field of view
	focal length = tan(fov angle in radian / 2)
*/
t_camera	camera(t_canvas *canvas, t_point3 orig, t_vec3 dir, double fov)
{
	t_camera	cam;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;

	cam.orig = orig;
	cam.focal_len = tan((fov * PI / 180.0) / 2.0);
	cam.viewport_h = cam.focal_len * 2;
	cam.viewport_w = cam.viewport_h * canvas->aspect_ratio;
	cam.dir = vunit(dir);
	w = vunit(vmult(dir, -1));
	u = vunit(vcross(cam_set_vup(dir), w));
	v = vcross(w, u);
	cam.horizontal = vmult(u, cam.viewport_w);
	cam.vertical = vmult(v, cam.viewport_h);
	cam.left_bottom = vminus(vminus(vminus(cam.orig,
					vdivide(cam.horizontal, 2)),
				vdivide(cam.vertical, 2)), w);
	return (cam);
}

void	world_init(t_object **world, t_parser *p)
{
	int	i;

	i = 0;
	while (i < p->s)
	{
		obj_add(world, object(SP, sphere(p->spheres[i].center, \
		p->spheres[i].diameter / 2), vdivide(p->spheres[i].rgb, 255)));
		i++;
	}
	i = 0;
	while (i < p->p)
	{
		obj_add(world, object(PL, plane(p->planes[i].coord, \
		p->planes[i].orientation, INFINITY), vdivide(p->planes[i].rgb, 255)));
		i++;
	}
	i = 0;
	while (i < p->cy)
	{
		obj_add(world, object(CY, cylinder(p->cylinders[i].coord, \
		p->cylinders[i].diameter / 2, p->cylinders[i].orientation, \
		p->cylinders[i].height), vdivide(p->cylinders[i].rgb, 255)));
		i++;
	}
}

t_scene	*scene_init(char *scene_file)
{
	t_scene		*scene;
	t_object	*world;
	t_parser	p;

	parser_init(&p, scene_file);
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (scene == NULL)
		error("scene malloc failed");
	scene->canvas = canvas(WIN_W, WIN_H);
	scene->camera = camera(&scene->canvas, p.camera.view_point, \
	p.camera.orientation, p.camera.fov);
	world = NULL;
	world_init(&world, &p);
	scene->world = world;
	scene->light = object(LIGHT_POINT, light_point(p.light.light_point, \
	vdivide(p.light.rgb, 255), p.light.ratio), color3(0, 0, 0));
	scene->ambient = vmult(vdivide(p.ambient_light.rgb, 255), \
	p.ambient_light.ratio);
	free_parser(&p);
	return (scene);
}
