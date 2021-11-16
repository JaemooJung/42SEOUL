/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:08 by jaemjung          #+#    #+#             */
/*   Updated: 2021/11/16 17:18:54 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h> //TODO : 나중에 지우기

void	free_str_nums(char **str_nums)
{
	int	i;

	i = 0;
	while (str_nums[i] != NULL)
	{
		free(str_nums[i]);
		str_nums[i] = NULL;
		i++;
	}
	free(str_nums);
	str_nums = NULL;
}

int	is_arg_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_and_append(t_node **node, char *arg)
{
	long long	value;

	if (is_arg_digit(arg) == 0)
		error_handler();
	value = ft_atoi(arg);
	if (value < INT_MIN || value > INT_MAX)
		error_handler();
	dupcheck_and_append(node, new_node((int)value));
}

int	check_arguments_and_append(int argc, char **argv)
{
	char	**str_nums;
	int		i;
	int		j;
	t_node	*node;

	i = 1;
	node = NULL;
	while (i < argc)
	{
		str_nums = ft_split(argv[i++], ' ');
		if (str_nums == NULL)
			error_handler();
		j = 0;
		while (str_nums[j] != NULL)
			check_and_append(&node, str_nums[j++]);
		free_str_nums(str_nums);
	}
	//TODO : 나중에 지우기
	while (node->next != NULL)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("%d\n", node->value);
	//---------------------
	return (0);
}
