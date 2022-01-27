/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/09/23 16:56:24 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static int	buff_to_container(char **ctnr, char *buff,
							ssize_t rd_sz)
{
	char	*tmp;

	if (rd_sz < 0)
	{
		free(*ctnr);
		*ctnr = NULL;
		return (0);
	}
	buff[rd_sz] = '\0';
	tmp = ft_strjoin(*ctnr, buff);
	if (!tmp)
	{
		free(*ctnr);
		*ctnr = NULL;
		return (0);
	}
	free(*ctnr);
	*ctnr = tmp;
	return (1);
}

static int	container_to_line(char **ctnr, char **line,
							char **nl, ssize_t rd_sz)
{
	char	*tmp;

	if (rd_sz < 0)
	{
		ft_free(*ctnr);
		return (GNL_ERROR);
	}
	**nl = '\0';
	*line = ft_strdup(*ctnr);
	if (!(*line))
	{
		ft_free(*ctnr);
		return (GNL_ERROR);
	}
	tmp = ft_strdup(*nl + 1);
	if (!(tmp))
	{
		ft_free(*ctnr);
		return (GNL_ERROR);
	}
	free(*ctnr);
	*ctnr = tmp;
	return (GNL_READ_SUCCESS);
}

static int	last_line(char **line, char **ctnr, ssize_t read_size)
{
	if (read_size < 0)
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	*line = ft_strdup(*ctnr);
	if (!(*line))
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	free(*ctnr);
	*ctnr = NULL;
	return (GNL_EOF);
}

int	get_next_line(int fd, char **line)
{
	static char	*ctnr[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*nl;
	ssize_t		read_size;

	if (!line || (fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	if (!ctnr[fd])
		ctnr[fd] = ft_strdup("");
	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		if (!(buff_to_container(&ctnr[fd], buff, read_size)))
			return (GNL_ERROR);
		nl = ft_strchr(ctnr[fd], '\n');
		if (nl)
			return (container_to_line(&ctnr[fd], line, &nl, read_size));
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	nl = ft_strchr(ctnr[fd], '\n');
	if (nl)
		return (container_to_line(&ctnr[fd], line, &nl, read_size));
	return (last_line(line, &ctnr[fd], read_size));
}
