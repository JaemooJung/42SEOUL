/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:19:29 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/09 22:41:58 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_has_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_initialize(char	*tmp_line)
{
	if (tmp_line)
		return (tmp_line);
	tmp_line = (char *)malloc(1 * sizeof(char));
	if (!tmp_line)
		return (NULL);
	tmp_line[0] = '\0';
	return (tmp_line);
}

char	*ft_strjoin2(char *tmp_line, char *buffer)
{
	size_t	i;
	size_t	j;
	int		size;
	char	*new_tmp_line;

	tmp_line = ft_initialize(tmp_line);
	if (!tmp_line)
		return (NULL);
	size = ft_strlen2(tmp_line) + ft_strlen2(buffer);
	new_tmp_line = (char *)malloc(sizeof(char) * size + 1);
	if (new_tmp_line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp_line[j])
		new_tmp_line[i++] = tmp_line[j++];
	j = 0;
	while (buffer[j])
		new_tmp_line[i++] = buffer[j++];
	new_tmp_line[i] = '\0';
	free(tmp_line);
	return (new_tmp_line);
}
