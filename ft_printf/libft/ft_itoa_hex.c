/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:10:53 by jaemjung          #+#    #+#             */
/*   Updated: 2021/07/14 20:53:09 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_numlen(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	make_num_str(char *str, long long n, int numlen)
{
	int	is_negative;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	else
		is_negative = 0;
	str[numlen] = '\0';
	numlen--;
	if (n == 0)
	{
		str[numlen] = '0';
		return ;
	}
	while (n > 0)
	{
		str[numlen] = "0123456789abcdef"[n % 16];
		n = n / 16;
		numlen--;
	}
	if (is_negative)
		str[numlen] = '-';
}

char	*ft_itoa_hex(long long n)
{
	char	*rtn;
	int		numlen;

	numlen = get_numlen(n);
	rtn = (char *)malloc((numlen + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	make_num_str(rtn, n, numlen);
	return (rtn);
}
