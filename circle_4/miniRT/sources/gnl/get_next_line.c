/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:19:18 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/27 18:25:18 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *tmp_line)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_has_n(tmp_line) == -1 && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp_line = ft_strjoin2(tmp_line, buffer);
	}
	free(buffer);
	return (tmp_line);
}

char	*ft_get_line(char *tmp_line)
{
	int		i;
	int		n;
	char	*next_line;

	i = 0;
	if (!tmp_line[i])
		return (NULL);
	n = ft_has_n(tmp_line);
	if (n == -1)
		n = ft_strlen2(tmp_line) - 1;
	next_line = (char *)malloc(sizeof(char) * (n + 2));
	if (!next_line)
		return (NULL);
	while (i < n + 1)
	{
		next_line[i] = tmp_line[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_new_tmp_line(char *tmp_line)
{
	size_t	i;
	size_t	size;
	int		n;
	char	*str;

	n = ft_has_n(tmp_line);
	str = NULL;
	if (n != -1)
	{
		size = ft_strlen2(tmp_line) - n;
		str = (char *)malloc(sizeof(char) * size + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (tmp_line[++n])
			str[i++] = tmp_line[n];
		str[i] = '\0';
	}
	free(tmp_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*tmp_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp_line = ft_read_line(fd, tmp_line);
	if (!tmp_line)
		return (NULL);
	next_line = ft_get_line(tmp_line);
	tmp_line = ft_new_tmp_line(tmp_line);
	return (next_line);
}
