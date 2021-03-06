/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:29:48 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/13 11:46:12 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*casted_dst;
	unsigned char	*casted_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	casted_dst = dst;
	casted_src = (unsigned char *)src;
	while (i < n)
	{
		*casted_dst = *casted_src;
		casted_dst++;
		casted_src++;
		i++;
	}
	return (dst);
}
