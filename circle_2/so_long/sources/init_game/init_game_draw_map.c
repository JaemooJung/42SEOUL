#include "../../includes/so_long.h"

static void	draw_wall_and_space(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall.image_pointer,
					j * TILE_SIZE, i * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.space.image_pointer,
					j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->tiles.player.image_pointer,
		game->player.current_x * TILE_SIZE,
		game->player.current_y * TILE_SIZE);
}

static void	draw_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->tiles.exit.image_pointer,
		game->exit.x * TILE_SIZE,
		game->exit.y * TILE_SIZE);
}

static void draw_collectibles(t_game *game)
{
	int i;
	
	i = 0;
	while (i < game->number_of_collectibles)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->tiles.collectible.image_pointer,
			game->collectibles[i].x * TILE_SIZE,
			game->collectibles[i].y * TILE_SIZE);
		i++;
	}
}

void	draw_map(t_game *game)
{
	draw_wall_and_space(game);
	draw_player(game);
	draw_exit(game);
	// TODO: 수집품 그리기
	draw_collectibles(game);
}