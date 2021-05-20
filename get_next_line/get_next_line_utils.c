/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:28:02 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/20 14:04:51 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char casted_c;
	char *tmp_s;

	casted_c = (char)c;
	tmp_s = (char *)s;
	while (*tmp_s)
	{
		if (*tmp_s == casted_c)
			return (tmp_s);
		tmp_s++;
	}
	if (casted_c == '\0')
		return (tmp_s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t src_len;

	if (!dst && !src)
		return (0);
	i = 0;
	src_len = ft_strlen((char *)src);
	if (dstsize == 0)
		return (src_len);
	while (i < src_len && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dstsize == 0)
		return (s_len);
	else if (dstsize <= d_len)
		return (dstsize + s_len);
	i = 0;
	while (src[i] != 0 && (d_len + i) < dstsize - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	rtn = (char *)malloc(s1_len + 1);
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	return (rtn);
}
