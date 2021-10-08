#include "../../includes/so_long.h"

static void	make_2d_map(t_map_info *map_info, t_game *game)
{
	char	**arr_map;
	int		i;

	arr_map = (char **)malloc(sizeof(char *) * (map_info->height + 1));
	if (arr_map == NULL)
		error_handler("2d map malloc failed.");
	i = 0;
	while (map_info->temp_map->next != NULL)
	{
		arr_map[i] = map_info->temp_map->content;
		map_info->temp_map = map_info->temp_map->next;
		i++;
	}
	arr_map[i] = map_info->temp_map->content;
	arr_map[++i] = NULL;
	game->map = arr_map;
	game->map_height = map_info->height;
	game->map_width = map_info->width;
	game->number_of_collectibles = map_info->number_of_collectibles;
}

static void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		error_handler("mlx init failed.");
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(TILE_SIZE * game->map_width),
			(TILE_SIZE * game->map_height),
			"so_long");
	if (game->win_ptr == NULL)
		error_handler("window init failed.");
}

static void	init_image(t_game *game)
{
	t_tiles	tiles;
	// TODO : 이미지 주소 설정하는법 알아내기. 
	tiles.wall.image_pointer = mlx_png_file_to_image(game->mlx_ptr,
			"/Users/jaemoojung/Desktop/42/42SEOUL/circle_2/so_long/imgs/map_wall.png", &tiles.wall.width, &tiles.wall.height);
	tiles.space.image_pointer = mlx_png_file_to_image(game->mlx_ptr,
			"/Users/jaemoojung/Desktop/42/42SEOUL/circle_2/so_long/imgs/map_space.png", &tiles.space.width, &tiles.space.height);
	tiles.player.image_pointer = mlx_png_file_to_image(game->mlx_ptr,
			"/Users/jaemoojung/Desktop/42/42SEOUL/circle_2/so_long/imgs/map_player.png", &tiles.player.width, &tiles.player.height);
	tiles.collectible.image_pointer = mlx_png_file_to_image(game->mlx_ptr,
			"/Users/jaemoojung/Desktop/42/42SEOUL/circle_2/so_long/imgs/map_collectible.png", &tiles.collectible.width, &tiles.collectible.height);
	tiles.exit.image_pointer = mlx_png_file_to_image(game->mlx_ptr,
			"/Users/jaemoojung/Desktop/42/42SEOUL/circle_2/so_long/imgs/map_exit.png", &tiles.exit.width, &tiles.exit.height);
	game->tiles = tiles;
}

int	init_game(t_map_info *map_info, t_game *game)
{
	make_2d_map(map_info, game);
	init_window(game);
	init_image(game);
	init_features(game);
	draw_map(game);
	return (0);
}
