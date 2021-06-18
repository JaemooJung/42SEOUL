/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/06/18 16:40:42 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	rtn = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	ft_strlcat(rtn, s2, s1_len + s2_len + 1);
	return (rtn);
}

int		buff_to_container(char **ctnr, char *buff, ssize_t rd_sz)
{
	char *tmp;

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

int		container_to_line(char **ctnr, char **line, char **nl, ssize_t rd_sz)
{
	char *tmp;

	if (rd_sz < 0)
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	**nl = '\0';
	if (!(*line = ft_strdup(*ctnr)))
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	if (!(tmp = ft_strdup(*nl + 1)))
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	free(*ctnr);
	*ctnr = tmp;
	return (GNL_READ_SUCCESS);
}

int		last_line(char **line, char **ctnr, ssize_t read_size)
{
	if (read_size < 0)
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	if (!(*line = ft_strdup(*ctnr)))
	{
		free(*ctnr);
		*ctnr = NULL;
		return (GNL_ERROR);
	}
	free(*ctnr);
	*ctnr = NULL;
	return (GNL_EOF);
}

int		get_next_line(int fd, char **line)
{
	static char *ctnr[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*nl;
	ssize_t		read_size;

	if (!line || (fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	if (!ctnr[fd])
		ctnr[fd] = ft_strdup("");
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (!(buff_to_container(&ctnr[fd], buff, read_size)))
			return (GNL_ERROR);
		if ((nl = ft_strchr(ctnr[fd], '\n')))
			return (container_to_line(&ctnr[fd], line, &nl, read_size));
	}
	if ((nl = ft_strchr(ctnr[fd], '\n')))
		return (container_to_line(&ctnr[fd], line, &nl, read_size));
	return (last_line(line, &ctnr[fd], read_size));
}
