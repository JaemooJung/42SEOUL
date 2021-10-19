#include "../../includes/so_long.h"

static void	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		check_wall_and_move(keycode, game);
		check_collectible(game);
		draw_map(game);
		printf("current move : %d\n", game->player.moves);
		check_exit(game);
	}
}

static void	terminate_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int	key_input_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		terminate_game(game);
	move_player(keycode, game);
	return (0);
}
