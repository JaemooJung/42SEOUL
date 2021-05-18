/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/18 17:02:50 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*file_content;
	char		*buff;
	ssize_t		read_size;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (LINE_ERROR);
	while (read_size = read(fd, buff, BUFFER_SIZE) > 0)
	{
		if (!file_content)
			file_content = ft_strdup(buff);
		else
			ft_strlcpy(file_content, buff, read_size + 1);
		if (ft_strchr())
	}
}
