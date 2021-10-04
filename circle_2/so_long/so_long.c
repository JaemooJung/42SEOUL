#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	void		*mlx_ptr;
	void		*win_ptr;
	if (argc != 2)
	{
		printf("Error\n%s\n", "Usage: ./so_long [Map file name]");
		exit(1);
	}
	ft_bzero(&map_info, sizeof(t_map_info));
	parse_map(argv[1], &map_info);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so_long");
	mlx_loop(mlx_ptr);
	return (0);
}