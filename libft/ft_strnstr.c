/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:29:10 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 13:48:30 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmp_haystack;
	char	*tmp_needle;
	int		curr;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		tmp_haystack = (char *)haystack;
		tmp_needle = (char *)needle;
		curr = len;
		while (*tmp_needle && (*tmp_needle == *tmp_haystack) && curr)
		{
			tmp_needle++;
			tmp_haystack++;
			curr--;
		}
		if (*tmp_needle == '\0')
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (0);
}
