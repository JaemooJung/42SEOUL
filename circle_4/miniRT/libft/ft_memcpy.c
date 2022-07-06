/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:45:17 by donghyun          #+#    #+#             */
/*   Updated: 2022/01/05 18:40:21 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char	*dst;

	if (!dest && !src)
		return (0);
	dst = dest;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (dest);
}
