/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:27:18 by jaemjung          #+#    #+#             */
/*   Updated: 2022/06/28 15:57:38 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	draw_pixel(t_mlx_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	free_scene(t_scene *scene)
{
	t_object	*temp;
	t_object	*head;

	head = scene->world;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->element);
		free(temp);
	}
	free(scene->light->element);
	free(scene->light);
	free(scene);
}

void	draw_scene(t_mlx_info *info, char *scene_file)
{
	int			i;
	int			j;
	t_color3	pixel_color;
	t_scene		*scene;

	scene = scene_init(scene_file);
	j = -1;
	while (++j < scene->canvas.height)
	{
		i = -1;
		while (++i < scene->canvas.width)
		{
			scene->ray = ray_primary(&scene->camera,
					(double)i / (scene->canvas.width - 1),
					(double)j / (scene->canvas.height - 1));
			pixel_color = ray_color(scene);
			draw_pixel(info, i, scene->canvas.height - j - 1,
				encode_color(pixel_color));
		}
	}
	free_scene(scene);
}
