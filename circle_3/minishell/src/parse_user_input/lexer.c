/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:34:02 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/16 12:02:19 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_token_type(char *token)
{
	if (token[0] == '|')
		return (T_PIPE);
	else if (token[0] == '>' || token[0] == '<')
		return (T_REDIRECTION);
	else if (token[0] == '\0')
		return (T_NULL);
	else
		return (T_WORD);
}

int	lexer(t_list *splitted, t_token **tokens)
{
	int		i;
	t_list	*tmp;

	*tokens = NULL;
	*tokens = (t_token *)malloc(sizeof(t_token)
			* (ft_lstsize(splitted) + 1));
	if (!(*tokens))
		return (MALLOC_ERR);
	i = 0;
	tmp = splitted;
	while (tmp != NULL)
	{
		(*tokens)[i].type = get_token_type(tmp->line);
		(*tokens)[i].value = ft_strdup(tmp->line);
		tmp = tmp->next;
		++i;
	}
	(*tokens)[i].value = NULL;
	(*tokens)[i].type = T_NULL;
	return (0);
}
