/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:06:29 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/28 17:57:45 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	replace_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
}

int	get_size(char *file, int id)
{
	int		i;
	int		fd;
	char	*line;
	char	**element;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_parser("failed to open file\n", file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		replace_space(line);
		element = ft_split(line, ' ');
		if (check_identifier(element[0]) == id)
			i++;
		free_pp(element);
		free(line);
	}
	close(fd);
	return (i);
}

int	count_element(char **element)
{
	int	i;

	i = 0;
	while (element[i])
		i++;
	return (i);
}

void	free_pp(char **pp)
{
	int	i;

	i = 0;
	while (pp[i])
	{
		free(pp[i]);
		pp[i++] = NULL;
	}
	free(pp);
	pp = NULL;
}

void	free_parser(t_parser *p)
{
	free(p->spheres);
	free(p->planes);
	free(p->cylinders);
}
