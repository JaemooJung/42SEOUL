/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:28:06 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/04 19:14:01 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memcpy.c"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*buffer;

	buffer = (unsigned char *)malloc(sizeof(unsigned char) * len);
	ft_memcpy(buffer, src, len);
	ft_memcpy(dst, buffer, len);
	free(buffer);
	return (dst);
}