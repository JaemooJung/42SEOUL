/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:43:44 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/07 16:47:20 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen((char *)src);
	d_len = ft_strlen(dst);
	if (dstsize == 0)
		return (s_len);
	i = 0;
	while (src[i] != 0 && (d_len + i) < dstsize - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	if (d_len < dstsize)
		return (d_len + s_len);
	return (dstsize + s_len);
}
