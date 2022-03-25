/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:15 by hakim             #+#    #+#             */
/*   Updated: 2022/03/15 16:06:17 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}	
	return (count);
}

static int	get_si(int *i, char const *s, char c)
{
	int	size;

	size = 0;
	while (s[*i] != '\0' && s[*i] == c)
		*i += 1;
	if (s[*i] == '\'')
	{
		while (s[*i] != '\0')
		{
			size += 1;
			*i += 1;
			if (s[*i] == '\'')
			{
				size += 1;
				*i += 1;
				return (size);
			}
		}
	}
	while (s[*i] != '\0' && s[*i] != c)
	{
		size += 1;
		*i += 1;
	}
	return (size);
}

static void	ft_free_split(char **splitted, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(splitted[i]);
		splitted[i] = 0;
		++i;
	}
	free(splitted);
	splitted = 0;
}

static void	go_split(char **big, char const *s, char c, int bigdex)
{
	int	i;
	int	size;
	int	sindex;

	i = 0;
	while (s[i] != '\0')
	{
		size = get_si(&i, s, c);
		if (size == 0)
			continue ;
		big[bigdex] = (char *)malloc(sizeof(char) * (size + 1));
		if (big[bigdex] == 0)
			return (ft_free_split(big, bigdex));
		sindex = 0;
		i -= size;
		while (sindex < size)
		{
			if (s[i] == '\'' && ++i)
				--size;
			else
				big[bigdex][sindex++] = s[i++];
		}
		big[bigdex++][sindex] = '\0';
	}
	big[bigdex] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	int		size;
	int		bigdex;

	if (s == 0)
		return (0);
	size = wordcount(s, c);
	big = (char **)malloc(sizeof(char *) * (size + 1));
	if (big == 0)
		return (0);
	bigdex = 0;
	go_split(big, s, c, bigdex);
	return (big);
}	
