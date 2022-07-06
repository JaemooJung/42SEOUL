/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:45:26 by donghyun          #+#    #+#             */
/*   Updated: 2022/01/05 18:54:45 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;

	if (!dest && !src)
		return (NULL);
	dst = dest;
	if ((size_t)(dest - src) >= n)
		while (n--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	else
		while (n--)
			*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	return (dest);
}
