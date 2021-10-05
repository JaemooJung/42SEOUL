#include "../../includes/so_long.h"

void	draw_wall_and_space(t_game *game)
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
