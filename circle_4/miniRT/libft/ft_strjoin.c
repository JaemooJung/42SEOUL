/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:45:04 by donghyun          #+#    #+#             */
/*   Updated: 2022/06/09 01:20:14 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_total;
	size_t	size_s1;
	char	*str;

	size_total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size_total + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size_s1 = ft_strlcpy(str, s1, size_total + 1);
	ft_strlcpy(str + size_s1, s2, size_total + 1);
	return (str);
}
