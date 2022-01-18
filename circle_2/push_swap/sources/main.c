/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:18 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/18 19:30:41 by jaemjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	node = NULL;
	check_arguments_and_append(argc, argv, &node);
	a = NULL;
	b = NULL;
	init_stacks(&node, &a, &b);
	//print_stack_info(a, 'a');
	//print_stack_info(b, 'b');
	a_to_b(&a, &b, a->size);
	//print_stack_info(a, 'a');
	//print_stack_info(b, 'b');
	exit(0);
}
