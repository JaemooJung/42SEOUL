/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:25:24 by jaemjung          #+#    #+#             */
/*   Updated: 2021/11/16 17:25:38 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (file_extension == NULL
		|| ft_strlen(file_extension) != 4
		|| ft_strncmp(file_extension, ".ber", 4) != 0)
		error_handler("Wrong file extension. only .ber file is avaliable");
	return (0);
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
	return (0);
}
