/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:11:26 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/07 16:50:03 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	rtn = malloc(count * size);
	if (rtn == NULL)
		return (NULL);
	ft_bzero(rtn, count * size);
	return (rtn);
}
