/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:06:32 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/15 15:45:59 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	j_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static size_t	j_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	if (!dst && !src)
		return (0);
	i = 0;
	src_len = j_strlen((char *)src);
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

static size_t	j_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	s_len = j_strlen(src);
	d_len = j_strlen(dst);
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

char	*j_strdup(const char *s1)
{
	char	*rtn;
	size_t	s1_len;

	s1_len = j_strlen(s1);
	rtn = (char *)malloc(s1_len + 1);
	if (rtn == NULL)
		return (NULL);
	j_strlcpy(rtn, s1, s1_len + 1);
	return (rtn);
}

char	*j_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (j_strdup(s2));
	else if (!s2)
		return (j_strdup(s1));
	s1_len = j_strlen(s1);
	s2_len = j_strlen(s2);
	rtn = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!rtn)
		return (NULL);
	j_strlcpy(rtn, s1, s1_len + 1);
	j_strlcat(rtn, s2, s1_len + s2_len + 1);
	return (rtn);
}
