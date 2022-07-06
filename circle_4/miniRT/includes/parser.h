/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:44:46 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/28 15:55:43 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "structures.h"
# include "error.h"
# include "../libft/libft.h"
# include "get_next_line.h"

void		parse_sphere(t_parser *scene, char **element);
void		parse_plane(t_parser *scene, char **element);
void		parse_cylinder(t_parser *scene, char **element);

double		parse_double(char *str);
double		parse_double_range(char *str, double from, double to);
t_vec3		parse_coordinate(char *str);
t_vec3		parse_coordinate_range(char *str, double from, double to, int norm);

void		parse_ambient(t_parser *scene, char **element);
void		parse_camera(t_parser *scene, char **element);
void		parse_light(t_parser *scene, char **element);

void		parse_line(t_parser *scene, char *line);
void		parse(t_parser *scene, char *file);
void		parser_init(t_parser *scene, char *file);

void		replace_space(char *str);
int			get_size(char *file, int id);
int			count_element(char **element);
void		free_pp(char **pp);
void		free_parser(t_parser *p);

int			check_identifier(char *id);
void		check_extension(char *file);
char		*check_number(char *num);

#endif