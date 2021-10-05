#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "../libft/libft.h"

typedef struct s_map_info
{
	t_list		*temp_map;
	int			height;
	int			width;
	int			number_of_collectibles;
	int			number_of_exit;
	int			number_of_player;
}				t_map_info;

int	parse_map(char *file_name, t_map_info *map_info);
int	check_map_first_line(char *line, t_map_info *map_info);
int	check_map_middle_line(char *line, t_map_info *map_info);
int	check_map_last_line(char *line, t_map_info *map_info);
int	check_for_last(t_map_info *map_info);

#endif