/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:19:22 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/28 00:08:55 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_read_line(int fd, char *tmp_line);
char	*ft_get_line(char *tmp_line);
char	*ft_new_tmp_line(char *tmp_line);
char	*get_next_line(int fd);
size_t	ft_strlen2(char *s);
int		ft_has_n(char *s);
char	*ft_initialize(char	*tmp_line);
char	*ft_strjoin2(char *tmp_line, char *buff);

#endif