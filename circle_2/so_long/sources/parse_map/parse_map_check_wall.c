#include "../../includes/so_long.h"

// TODO : 첫번째 라인 처리
int	check_map_first_line(char *line, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			error_handler("Wrong map format.");
		i++;
	}
	if (i == 0)
		error_handler("Wrong map format.");
	else
	{
		map_info->width = i;
		map_info->temp_map = ft_lstnew(line);
		if (map_info->temp_map == NULL)
			error_handler("Failed to create temp_map.");
	}
	return (0);
}

// 중간 라인 처리
// 맨 처음 인덱스와 마지막 인덱스는 1(벽인지 체크)
// 중간에 가다가 P, C, E 를 만나는지 체크. 있으면 구조체 내부에 해당 변수 증가
int	check_map_middle_line(char *line, t_map_info *map_info)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (line[i] != '\0')
	{
		if (i == 0 && line[i] != '1')
			error_handler("Wrong map format.");
		if (line[i] == 'E')
			map_info->number_of_exit++;
		else if (line[i] == 'C')
			map_info->number_of_collectibles++;
		else if (line[i] == 'P')
			map_info->number_of_player++;
		else if (i != 0 && !(line[i] == '0' || line[i] == '1'))
			error_handler("Wrong map format.");
		i++;
	}
	if (line[i - 1] != '1' || i != map_info->width)
		error_handler("Wrong map format.");
	tmp = ft_lstnew(line);
	if (tmp == NULL)
		error_handler("Failed to create temp_map.");
	ft_lstadd_back(&map_info->temp_map, tmp);
	return (0);
}

//TODO : 마지막 라인 처리 
int	check_map_last_line(char *line, t_map_info *map_info)
{
	int i;
	t_list *tmp;
	
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			error_handler("Wrong map format.");
		i++;
	}
	if (i != map_info->width)
		error_handler("Wrong map format.");
	tmp = ft_lstnew(line);
	ft_lstadd_back(&map_info->temp_map, tmp);
	return (0);
}
//각 라인에서 오류가 없으면 연결리스트에 해당 라인 저장

//최종적으로 구조체 검사. P나 C나 E의 갯수가 올바르지 않으면 에러 메세지 표시 후 종료.
int	check_for_last(t_map_info *map_info)
{
	if (map_info->number_of_player > 1 ||
		map_info->number_of_collectibles < 1 ||
		map_info->number_of_exit > 1)
		error_handler("Wrong map format.");
	map_info->height = ft_lstsize(map_info->temp_map);
	return (0);
}