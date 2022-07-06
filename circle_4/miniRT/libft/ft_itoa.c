/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:37:19 by donghyun          #+#    #+#             */
/*   Updated: 2022/01/05 20:22:32 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(int n)
{
	size_t	size;

	size = 0;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = get_len(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * size + 2);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		size += 1;
		n *= -1;
	}
	str[size--] = '\0';
	while (n)
	{
		str[size--] = "0123456789"[n % 10];
		n = n / 10;
	}
	return (str);
}
