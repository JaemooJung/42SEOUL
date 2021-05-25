/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/25 18:40:32 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*save_file_content(char *file_content, char *buff)
{
	char *temp_content;

	if (!file_content)
		file_content = ft_strdup(buff);
	else
	{
		temp_content = file_content;
		file_content = ft_strjoin(file_content, buff);
		free(temp_content);
	}
	if (!file_content)
		return (NULL);
	return (file_content);
}

int		fill_ln_rtn(char **line, char **file_content, char **nl_point)
{
	char *temp_content;

	**nl_point = '\0';
	*line = ft_strdup(*file_content);
	temp_content = *file_content;
	*file_content = ft_strdup(*nl_point + 1);
	free(temp_content);
	if (!(*file_content))
		return (LINE_ERROR);
	return (LINE_READ_SUCCESS);
}

int		get_next_line(int fd, char **line)
{
	static char	*f_contents[OPEN_MAX];
	char		*buff;
	ssize_t		read_size;
	char		*nl_ptr;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (LINE_ERROR);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		f_contents[fd] = save_file_content(f_contents[fd], buff);
		if (!f_contents[fd])
			return (LINE_ERROR);
		if ((nl_ptr = ft_strchr(f_contents[fd], '\n')))
		{
			free(buff);
			return (fill_ln_rtn(line, &f_contents[fd], &nl_ptr));
		}
	}
	if ((nl_ptr = ft_strchr(f_contents[fd], '\n')))
	{
		free(buff);
		return (fill_ln_rtn(line, &f_contents[fd], &nl_ptr));
	}
	*line = ft_strdup(f_contents[fd]);
	free(buff);
	return (LINE_FILE_EOF);
}
