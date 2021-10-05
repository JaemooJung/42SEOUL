#include "../../includes/so_long.h"


static int	check_map_validity(int map_fd, t_map_info *map_info)
{
	char	*line;
	int		gnl_check;
	int		first_ln_done;

	first_ln_done = 0;
	gnl_check = get_next_line(map_fd, &line);
	while (gnl_check > 0)
	{
		if (!first_ln_done)
		{
			check_map_first_line(line, map_info);
			first_ln_done = 1;
		}
		else
			check_map_middle_line(line, map_info);
		gnl_check = get_next_line(map_fd, &line);
	}
	if (gnl_check < 0)
		error_handler("Failed to read from map file");
	check_map_last_line(line, map_info);
	check_for_last(map_info);
	return (0);
}

static int	check_file_extension(char *file_name)
{
	char	*file_extension;

	file_extension = ft_strrchr(file_name, '.');
	if (file_extension == NULL || ft_strncmp(file_extension, ".ber", 4) != 0)
	{
		printf("Error\nWrong file extension. only .ber file is avaliable");
		exit(1);
	}
	else
		return (0);
}

void print_map_iter(void *content)
{
	printf("%s\n", (char *)content);
}

void print_map(t_map_info *map_info)
{
	ft_lstiter(map_info->temp_map, &print_map_iter);
}

int	parse_map(char *file_name, t_map_info *map_info)
{
	int	map_fd;

	check_file_extension(file_name);
	map_fd = open(file_name, O_RDONLY);
	if (map_fd < 0)
	{
		printf("Error\n%s", strerror(errno));
		exit(errno);
	}
	check_map_validity(map_fd, map_info);
	print_map(map_info);
	return (0);
}