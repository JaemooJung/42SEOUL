/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:36:46 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/09 14:20:41 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;

    if (!s)
        return (NULL);
	rtn = (char *)malloc(len * sizeof(char) + 1);
    if (rtn == NULL)
        return (NULL);
	ft_strlcpy(rtn, s + start, len + 1);
    return (rtn);
}