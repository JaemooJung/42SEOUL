#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	t_game		game;

	if (argc != 2)
	{
		printf("Error\n%s\n", "Usage: ./so_long [Map file name]");
		exit(1);
	}
	ft_bzero(&map_info, sizeof(t_map_info));
	parse_map(argv[1], &map_info);
	ft_bzero(&game, sizeof(t_game));
	init_game(&map_info, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
