/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:45:35 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/16 14:55:57 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != T_NULL)
	{
		free(tokens[i].value);
		tokens[i].value = NULL;
		i++;
	}
	free(tokens);
}

static int	check_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp->type != T_NULL)
	{
		if (tmp->type == T_REDIRECTION && (tmp + 1)->type != T_WORD)
		{
			printf("minishell: parse error near '%s'\n", tmp->value);
			return (1);
		}
		tmp++;
	}
	return (0);
}

int	parse_user_input(const char *input, t_ast_node **tree,
	t_list *our_env, int exit_status)
{
	t_list	*splitted;
	t_token	*tokens;
	t_token	*tmp;
	int		rtn;

	splitted = NULL;
	rtn = split_input(input, &splitted);
	if (rtn == MALLOC_ERR)
	{
		ft_free_lst(splitted);
		return (rtn);
	}
	lexer(splitted, &tokens);
	if (check_tokens(tokens))
	{
		free_tokens(tokens);
		ft_free_lst(splitted);
		return (PARSE_ERROR);
	}
	tmp = tokens;
	parser(&tmp, tree);
	rtn = expand_env(*tree, our_env, exit_status);
	free_tokens(tokens);
	ft_free_lst(splitted);
	return (rtn);
}
