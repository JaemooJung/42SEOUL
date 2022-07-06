/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:33:55 by jaemjung          #+#    #+#             */
/*   Updated: 2022/07/03 19:40:45 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_mlx_info	info;

	if (ac != 2)
		error("Usage: ./miniRT scene_file.rt");
	init_mlx(&info);
	draw_scene(&info, av[1]);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_hook(info.win_ptr, X_EVENT_KEY_EXIT, 0, terminate, &info);
	mlx_key_hook(info.win_ptr, key_hook, &info);
	mlx_loop(info.mlx_ptr);
}
