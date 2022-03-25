/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:31:58 by hakim             #+#    #+#             */
/*   Updated: 2022/03/16 17:56:06 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_the_case(t_ast_node *node)
{
	if (node == NULL)
		return (false);
	if (node->left == NULL)
		return (false);
	if (node->left->left == NULL)
		return (false);
	if (node->left->left->left == NULL)
		return (false);
	if (node->left->right->left != NULL)
		return (false);
	return (true);
}

static void	collect_remainders(t_ast_node *tree)
{
	t_list	*remainder;

	if (is_the_case(tree) == false)
		return ;
	remainder = NULL;
	search_for_remainder(tree, &remainder);
}

static void	apocalypse(void)
{
	printf("\033[1A");
	printf("\033[10C");
	printf("exit\n");
	exit(0);
}

static void	minimum_viable_shell(t_list *env)
{
	static int	exit_status;
	char		*cmdline;
	t_ast_node	*tree;
	int			err_code;

	tree = NULL;
	cmdline = readline("minishell $ ");
	if (cmdline == NULL)
		apocalypse();
	if (cmdline[0] != '\0')
		add_history(cmdline);
	err_code = parse_user_input(cmdline, &tree, env, exit_status);
	if (err_code)
	{
		handle_parse_error(err_code, &exit_status);
		clear_ast(tree);
		ft_free_str(cmdline);
		return ;
	}
	collect_remainders(tree);
	run_tokens(tree, env, &exit_status);
	clear_ast(tree);
	ft_free_str(cmdline);
}

int	main(int argc, char **argv, char **envp)
{
	t_list			*our_env;
	struct termios	term;

	printf("Hello, world!\n");
	printf("hello, minishell!\n");
	(void)argv;
	(void)argc;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal_handler_init();
	our_env = envp_to_ours(envp);
	if (our_env == NULL)
		exit(ft_print_error(NULL, NULL, "Fatal error: initialization failed."));
	if (add_shlvl(our_env) == FAILURE)
		exit(ft_print_error(NULL, NULL, "Fatal error: initialization failed."));
	while (1)
		minimum_viable_shell(our_env);
}
