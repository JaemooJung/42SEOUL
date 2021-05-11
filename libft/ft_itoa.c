/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:10:53 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/11 15:09:38 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_numlen(int n)
{
	int	len;

	if (n == -2147483648)
		return (11);
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
		n = n / 10;
		len++;
	}
	return (len);
}

static void		make_num_str(char *str, long int n, int numlen)
{
	int sign;

	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	else
		sign = 0;
	str[numlen] = '\0';
	numlen--;
	if (n == 0)
	{
		str[numlen] = '0';
		return ;
	}
	while (n > 0)
	{
		str[numlen] = '0' + (n % 10);
		n = n / 10;
		numlen--;
	}
	if (sign)
		str[numlen] = '-';
}

char			*ft_itoa(int n)
{
	char	*rtn;
	int		numlen;

	numlen = get_numlen(n);
	rtn = (char *)malloc((numlen + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	make_num_str(rtn, (long int)n, numlen);
	return (rtn);
}
