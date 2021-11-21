/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:25:28 by jaemjung          #+#    #+#             */
/*   Updated: 2021/11/22 04:43:33 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	terminate_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_game		game;

	if (argc != 2)
		error_handler("Usage: ./so_long [Map file name]");
	ft_bzero(&map_info, sizeof(t_map_info));
	parse_map(argv[1], &map_info);
	ft_bzero(&game, sizeof(t_game));
	init_game(&map_info, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_input_handler, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &terminate_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
