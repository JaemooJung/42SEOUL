#ifndef INIT_GAME_H
# define INIT_GAME_H

# define TILE_SIZE 32

typedef struct s_image
{
	void		*image_pointer;
	int			height;
	int			width;

}				t_image;

typedef struct s_tiles
{
	t_image		wall;
	t_image		space;
	t_image		player;
	t_image		collectible;
	t_image		exit;
}				t_tiles;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			map_height;
	int			map_width;
	t_tiles		tiles;
}				t_game;

int		init_game(t_map_info *map_info, t_game *game);
void	draw_wall_and_space(t_game *game);

#endif