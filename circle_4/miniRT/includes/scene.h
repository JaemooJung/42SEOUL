/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:13:43 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/28 15:18:43 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"
# include "minirt.h"
# include "trace.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 orig, t_vec3 dir, double fov);

t_sphere	*sphere(t_point3 center, double radius);
t_cylinder	*cylinder(t_point3 center, double radius, t_vec3 dir,
				double height);
void		attach_cy_cap(t_object **objs, t_object *cy_);
t_plane		*plane(t_point3 center, t_vec3 dir, double radius);
t_object	*object(t_object_type type, void *element, t_color3 albedo);

t_light		*light_point(t_point3 light_origin,
				t_color3 light_color, double bright_ratio);

void		world_init(t_object **world, t_parser *p);
t_scene		*scene_init(char *scene_file);
void		draw_scene(t_mlx_info *info, char *scene_file);

#endif