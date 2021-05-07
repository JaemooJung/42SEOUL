/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:19:44 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/07 16:48:52 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char casted_c;
	char *tmp_s;

	casted_c = (char)c;
	tmp_s = (char *)s;
	while (*tmp_s)
	{
		if (*tmp_s == casted_c)
			return (tmp_s);
		tmp_s++;
	}
	if (casted_c == '\0')
		return (tmp_s);
	return (NULL);
}
