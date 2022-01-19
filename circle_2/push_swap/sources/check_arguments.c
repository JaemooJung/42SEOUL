/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:08 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/19 13:38:27 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_sorted(t_node **list)
{
	t_node	*temp;

	temp = *list;
	while (temp != NULL)
	{
		if (temp->next != NULL && temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_arguments_and_append(int argc, char **argv, t_node **node)
{
	char	**str_nums;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		str_nums = ft_split(argv[i++], ' ');
		if (str_nums == NULL)
			error_handler();
		j = 0;
		while (str_nums[j] != NULL)
			check_and_append(node, str_nums[j++]);
		free_str_nums(str_nums);
	}
	if (*node == NULL)
		exit(1);
	if (is_sorted(node) == 1)
		exit(1);
	return (0);
}
