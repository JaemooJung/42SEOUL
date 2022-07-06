/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:17:59 by donghyun          #+#    #+#             */
/*   Updated: 2022/01/05 18:32:06 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	while (n--)
	{
		c1 = (unsigned char *) s1++;
		c2 = (unsigned char *) s2++;
		if (*c1 != *c2)
			return (*c1 - *c2);
	}
	return (0);
}
