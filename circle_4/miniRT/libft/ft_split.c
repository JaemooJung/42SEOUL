/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:09:09 by donghyun          #+#    #+#             */
/*   Updated: 2022/01/05 19:32:12 by donghyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_to_sep(char const *str, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (size);
		i++;
		size++;
	}
	return (size);
}

int	get_words_num(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*get_word(char const *str, char c)
{
	char	*word;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen_to_sep(str, c);
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**ans;

	size = get_words_num(s, c);
	ans = (char **)malloc(sizeof(char *) * size + 1);
	if (!ans)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			ans[j++] = get_word(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
	}
	ans[j] = 0;
	return (ans);
}
