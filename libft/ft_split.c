/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:11:44 by jaemjung          #+#    #+#             */
/*   Updated: 2021/05/10 15:57:28 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
			if (!*s)
				return (count);
		}
		s++;
	}
	return (count);
}

void		free_words(char **result, int i)
{
	if (i > 0)
	{
		while (i != 0)
		{
			free(result[i]);
			result[i] = NULL;
			i--;
		}
	}
	free(result);
}

int			split_words(char **result, char const *s, char c, int i)
{
	char	*word;
	int		j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	word = (char *)malloc(sizeof(char) * (j + 1));
	if (!word)
	{
		free_words(result, i);
		return (0);
	}
	ft_strlcpy(word, s, j + 1);
	result[i] = word;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**rtn;
	int		i;

	if (!s)
		return (NULL);
	rtn = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(split_words(rtn, s, c, i)))
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	rtn[i] = NULL;
	return (rtn);
}
