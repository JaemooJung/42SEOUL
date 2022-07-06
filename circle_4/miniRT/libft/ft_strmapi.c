/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:31:40 by donghyun          #+#    #+#             */
/*   Updated: 2022/01/03 16:44:24 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ans;

	i = 0;
	ans = ft_strdup(s);
	if (!ans)
		return (NULL);
	while (ans[i])
	{
		ans[i] = f(i, ans[i]);
		i++;
	}
	return (ans);
}
