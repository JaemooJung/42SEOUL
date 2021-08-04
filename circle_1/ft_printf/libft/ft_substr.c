/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:36:46 by jaemjung          #+#    #+#             */
/*   Updated: 2021/07/15 21:09:22 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return ((char *)ft_calloc((len + 1), sizeof(char)));
	rtn = (char *)malloc((len + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, s + start, len + 1);
	return (rtn);
}
