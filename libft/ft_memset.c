/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:08:48 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/04 19:09:49 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	unsigned char	casted_c;
	size_t			i;

	i = 0;
	temp = b;
	casted_c = c;
	while (i < len)
	{
		*temp = casted_c;
		i++;
		temp++;
	}
	return (b);
}
