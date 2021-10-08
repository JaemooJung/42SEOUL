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

typedef struct s_player
{
	int			current_x;
	int			current_y;
	int			moves;
	int			did_collect;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
	int			is_opened;
}				t_exit;

typedef struct s_collectible
{
	int			x;
	int			y;
	int			is_collected;
}				t_collectible;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				map_height;
	int				map_width;
	int				number_of_collectibles;
	t_tiles			tiles;
	t_player		player;
	t_exit			exit;
	t_collectible	*collectibles;
}					t_game;

int		init_game(t_map_info *map_info, t_game *game);
void	draw_map(t_game *game);
void	init_features(t_game *game);

#endif