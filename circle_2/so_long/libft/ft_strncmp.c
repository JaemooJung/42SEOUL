/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:29:07 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/13 12:05:28 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*casted_s1;
	unsigned char	*casted_s2;

	if (n == 0)
		return (0);
	i = 0;
	casted_s1 = (unsigned char *)s1;
	casted_s2 = (unsigned char *)s2;
	while (i < n && casted_s1[i] && casted_s2[i])
	{
		if (casted_s1[i] != casted_s2[i])
			return (casted_s1[i] - casted_s2[i]);
		i++;
	}
	if (i == n)
		i--;
	return (casted_s1[i] - casted_s2[i]);
}
