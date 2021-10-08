#include "../../includes/so_long.h"
static void	init_player(t_game *game, int x, int y)
{
	game->player.current_x = x;
	game->player.current_y = y;
	game->player.moves = 0;
	game->player.did_collect = 0;
}

static void	init_exit(t_game *game, int x, int y)
{
	game->exit.x = x;
	game->exit.y = y;
	game->exit.is_opened = 0;
}

void	init_features(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				init_player(game, j, i);
			// TODO : 수집품 초기화하기
			// __________________
			else if (game->map[i][j] == 'E')
				init_exit(game, j, i);
			j++;
		}
		i++;
	}
}