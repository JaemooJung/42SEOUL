#include "../../includes/so_long.h"

void	check_exit(t_game *game)
{
	if (game->player.did_collect != game->number_of_collectibles)
		return ;
	if (game->exit.x == game->player.current_x
		&& game->exit.y == game->player.current_y)
	{
		game->exit.is_opened = 1;
		printf("_____YOU WIN!_____\n");
		printf("Your total move : %d\n", game->player.moves);
		exit(0);
	}
}

void	check_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->number_of_collectibles)
	{
		if (game->collectibles[i].x == game->player.current_x
			&& game->collectibles[i].y == game->player.current_y
			&& game->collectibles[i].is_collected == 0)
		{
			game->player.did_collect++;
			game->collectibles[i].is_collected = 1;
		}
		i++;
	}
}

void	check_wall_and_move(int keycode, t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.current_x;
	tmp_y = game->player.current_y;
	if (keycode == KEY_W
		&& game->map[game->player.current_y - 1][game->player.current_x]
		!= '1')
		game->player.current_y--;
	else if (keycode == KEY_A
		&& game->map[game->player.current_y][game->player.current_x - 1]
		!= '1')
		game->player.current_x--;
	else if (keycode == KEY_S
		&& game->map[game->player.current_y + 1][game->player.current_x]
		!= '1')
		game->player.current_y++;
	else if (keycode == KEY_D
		&& game->map[game->player.current_y][game->player.current_x + 1]
		!= '1')
		game->player.current_x++;
	if (game->player.current_x != tmp_x || game->player.current_y != tmp_y)
		printf("current move : %d\n", ++game->player.moves);
}
