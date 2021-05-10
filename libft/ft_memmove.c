/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:28:06 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 16:52:59 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!src && !dst)
		return (NULL);
	if (dst <= src)
	{
		tmp_src = (unsigned char *)src;
		tmp_dst = (unsigned char *)dst;
		while (len--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		tmp_dst = (unsigned char *)dst + len;
		tmp_src = (unsigned char *)src + len;
		while (len--)
			*--tmp_dst = *--tmp_src;
	}
	return (dst);
}
