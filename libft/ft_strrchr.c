/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:29:11 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/07 16:50:53 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *last_c;
	char casted_c;

	last_c = 0;
	casted_c = (char)c;
	while (*s)
	{
		if (*s == casted_c)
		{
			last_c = (char *)s;
		}
		s++;
	}
	if (casted_c == '\0')
		return ((char *)s);
	return (last_c);
}
