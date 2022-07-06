/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:52:45 by donghyun          #+#    #+#             */
/*   Updated: 2022/05/29 15:53:07 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int	from;
	int	to;

	if (!s1 || !set)
		return (0);
	from = 0;
	while (s1[from])
	{
		if (!(ft_strchr(set, s1[from++])))
			break ;
	}
	if (from == (int)ft_strlen(s1) && ft_strchr(set, s1[from - 1]))
		return (ft_strdup(""));
	to = ft_strlen(s1) - 1;
	while (to >= 0)
	{
		if (!(ft_strchr(set, s1[to--])))
			break ;
	}
	return ((char *)ft_substr(s1, from - 1, to - from + 3));
}
