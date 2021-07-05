/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:26:20 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 15:07:33 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	rtn = (char *)malloc(s1_len + 1);
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	return (rtn);
}
