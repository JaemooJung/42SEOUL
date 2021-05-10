/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:57:32 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 12:33:57 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*casted_dst;
	unsigned char	*casted_src;
	unsigned char	casted_c;
	size_t			i;

	casted_dst = dst;
	casted_src = (unsigned char *)src;
	casted_c = c;
	i = 0;
	while (i < n)
	{
		casted_dst[i] = casted_src[i];
		if (casted_src[i] == casted_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
