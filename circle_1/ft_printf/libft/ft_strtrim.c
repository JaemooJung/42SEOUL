/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:12:01 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 14:29:58 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	size_t	front;
	size_t	rear;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && (rear - 1 > 1))
		rear--;
	if (front > rear)
		return (ft_strdup(""));
	rtn = (char *)malloc((rear - front) * sizeof(char) + 1);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1 + front, rear - front + 1);
	return (rtn);
}
