/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/25 17:26:47 by jaemjung         ###   ########.fr       */
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
		file_content = ft_strjoin(file_content,buff);
		free(temp_content);
	}
	if (!file_content)
		return (NULL);
	return (file_content);
}

int		fill_ln_and_reset_container(char **line, char **file_content)
{
	char *new_line_point;
	char *temp_content;

	if ((new_line_point = ft_strchr(*file_content, '\n')))
	{
		*new_line_point = '\0';
		*line = ft_strdup(*file_content);
		temp_content = *file_content;
		*file_content = ft_strdup(new_line_point + 1);
		free(temp_content);
		if (!(*file_content))
			return (-1);
		return (1);
	}
	return (0);
}

int		return_result()
{
	
}

int		get_next_line(int fd, char **line)
{
	static char	*file_contents[OPEN_MAX];
	char		*buff;
	ssize_t		read_size;
	int			ln_check;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (LINE_ERROR);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		file_contents[fd] = save_file_content(file_contents[fd], buff);
		if (!file_contents[fd])
			return (LINE_ERROR);
		ln_check = fill_ln_and_reset_container(line, &file_contents[fd]);
		if (ln_check < 0)
			return (LINE_ERROR);
		else if (ln_check == 1)
		{
			free(buff);
			return (LINE_READ_SUCCESS);
		}
		if (!(*file_contents[fd]))
		{
			*line = ft_strdup("");
			free(file_contents[fd]);
			free(buff);
			return (LINE_FILE_EOF);
		}
	}
	// 버퍼 사이즈가 충분히 커서 이미 contents에 다 내용이 들어온 경우도 처리해줘야함... 어떻게 처리할 것인가?
	free(buff);
	return ();
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char* line;
	int	check;
	int	fd;

	fd = open("test.txt", O_RDONLY);
	while ((check = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}