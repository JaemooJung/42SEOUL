/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:36:46 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 16:53:42 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *)calloc(1, sizeof(char)));
	rtn = (char *)malloc(len * sizeof(char) + 1);
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, s + start, len + 1);
	return (rtn);
}
