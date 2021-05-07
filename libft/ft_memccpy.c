/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:57:32 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/07 16:48:52 by jaemjung         ###   ########.fr       */
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
		if (*casted_dst == casted_c)
			return ((void *)casted_dst++);
		*casted_dst = *casted_src;
		casted_dst++;
		casted_src++;
		i++;
	}
	return (0);
}
