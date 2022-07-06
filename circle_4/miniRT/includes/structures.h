/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:13:40 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/03 19:28:47 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef int				t_object_type;
# define SP 0
# define CY 1
# define PL 2
# define LIGHT_POINT 10

# define EPSILON 1e-6
# define PI 3.14159265359

typedef int				t_bool;
# define FALSE 0
# define TRUE 1

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

typedef struct s_mlx_info
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx_info;

typedef struct s_disc
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
}	t_disc;

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

typedef struct s_phong_light
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
	double		light_len;
	t_ray		light_ray;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
}	t_phong_light;

# define KSN 64
# define KS 0.3

typedef struct s_camera
{
	t_point3	orig;
	t_vec3		dir;
	double		focal_len;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	t_point3	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
}	t_hit_record;

typedef struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
}	t_sphere;

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		dir;
	double		radius;
	double		radius2;
	double		height;
}	t_cylinder;

typedef struct s_plane
{
	t_point3	center;
	t_vec3		dir;
	double		radius;
}	t_plane;

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

typedef struct s_parser_ambient
{
	double		ratio;
	t_color3	rgb;
}	t_parser_ambient;

typedef struct s_parser_camera
{
	t_point3	view_point;
	t_vec3		orientation;
	double		fov;
}	t_parser_camera;

typedef struct s_parser_light
{
	t_point3	light_point;
	double		ratio;
	t_color3	rgb;
}	t_parser_light;

typedef struct s_parser_sphere
{
	t_point3	center;
	double		diameter;
	t_color3	rgb;
}	t_parser_sphere;

typedef struct s_parser_plane
{
	t_point3	coord;
	t_vec3		orientation;
	t_color3	rgb;
}	t_parser_plane;

typedef struct s_parser_cylinder
{
	t_point3	coord;
	t_vec3		orientation;
	double		diameter;
	double		height;
	t_color3	rgb;
}	t_parser_cylinder;

typedef struct s_parser
{
	t_parser_ambient	ambient_light;
	t_parser_camera		camera;
	t_parser_light		light;
	int					s;
	t_parser_sphere		*spheres;
	int					p;
	t_parser_plane		*planes;
	int					cy;
	t_parser_cylinder	*cylinders;
}	t_parser;

#endif