/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:20:02 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/04 19:29:17 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t 			i;
	unsigned char	*casted_s;
	unsigned char	casted_c;

	i = 0;
	casted_c = c;
	casted_s = (unsigned char *)s;
	

	while (i < n)
	{
		if (*casted_s == casted_c)
			return ((void *)casted_s);
		casted_s++;
		i++;
	}
	return (0);
}