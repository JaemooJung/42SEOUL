/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:27:36 by jaemjung          #+#    #+#             */
/*   Updated: 2021/06/18 13:06:38 by jaemjung         ###   ########.fr       */
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

void	ft_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char *container;
	char		buff[BUFFER_SIZE + 1];
	char		*nl_ptr;
	char		*tmp;
	int			read_size;
	
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	if (!container)
		container = ft_strdup("");
	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (read_size < 0)
			return (GNL_ERROR);
		buff[read_size] = '\0';	
		tmp = ft_strjoin(container, buff);
		ft_free(container);
		container = tmp;
		if ((nl_ptr = ft_strchr(container, '\n')))
		{
			*nl_ptr = '\0';
			*line = ft_strdup(container);
			tmp = ft_strdup(nl_ptr + 1);
			ft_free(container);
			container = tmp;
			return (GNL_READ_SUCCESS);
		}
	}
	if (read_size < 0)
		return (GNL_ERROR);
	if ((nl_ptr = ft_strchr(container, '\n')))
	{
		*nl_ptr = '\0';
		*line = ft_strdup(container);
		tmp = ft_strdup(nl_ptr + 1);
		ft_free(container);
		container = tmp;
		return (GNL_READ_SUCCESS);
	}
	*line = ft_strdup(container);
	ft_free(container);
	container = ft_strdup("");
	return (GNL_EOF);
}
