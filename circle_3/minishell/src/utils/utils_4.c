/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:31 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 16:06:32 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = s;
	i = 0;
	while (i < n)
	{
		*temp = 0;
		i++;
		temp++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = malloc(count * size);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, count * size);
	return (rtn);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *)ft_calloc((len + 1), sizeof(char)));
	rtn = (char *)malloc((len + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, s + start, len + 1);
	return (rtn);
}
