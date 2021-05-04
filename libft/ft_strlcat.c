/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:43:44 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/04 17:16:41 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int s_len;
	unsigned int d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (size == 0)
		return (s_len);
	i = 0;
	while (src[i] != 0 && (d_len + i) < size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	if (d_len < size)
		return (d_len + s_len);
	return (size + s_len);
}
