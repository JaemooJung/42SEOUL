/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/20 14:51:38 by jaemjung         ###   ########.fr       */
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



int	get_next_line(int fd, char **line)
{
	static char	*file_content;
	char		*buff;
	char		*temp_content;
	ssize_t		read_size;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (LINE_ERROR);
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		// 버퍼의 내용을 콘텐트로 옮겨줌. 콘텐트가 null이면 buff의 내용을 content로 strdup 아니면 이전 strjoin으로 새로운 콘텐트를 만들고 이전 콘텐트를 프리
		if (!file_content)
			file_content = ft_strdup(buff);
		else
		{
			temp_content = file_content;
			file_content = ft_strjoin(file_content, buff);
			free(temp_content);
		}
		// 파일콘텐트에서 '\n'을 찾으면
		// 콘텐트의 '\n'을 0으로 바꿔주고 *line으로 strlcpy.
		// 콘텐트의 주소값을 다음으로 옮김.
		// 1 리턴
		if (ft_strchr(file_content, '\n'))
		{
			*(ft_strchr(file_content, '\n')) = '\0';
			ft_strlcpy(*line, file_content, ft_strlen(file_content) + 1);
			file_content = ft_strchr(file_content, '\0') + 1;
			free(buff);
			return (LINE_READ_SUCCESS);
		}
		//eof를 만나면
		//남아있는 str을 line에 넣어주고
		//0 리턴
	}
	return (LINE_FILE_EOF);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *line;
	int fd;

	line = (char *)malloc(100);
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
}