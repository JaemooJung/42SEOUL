/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:28:38 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/07 16:47:52 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	char	casted_c;

	casted_c = (char)c;
	if (casted_c >= 'A' && casted_c <= 'Z')
		return (1);
	else if (casted_c >= 'a' && casted_c <= 'z')
		return (2);
	else
		return (0);
}
