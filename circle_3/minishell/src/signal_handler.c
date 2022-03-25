/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:46:40 by jaemoojung        #+#    #+#             */
/*   Updated: 2022/03/16 16:26:02 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(pid_t pid)
{
	if (pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	handle_sigquit(pid_t pid)
{
	if (pid == -1)
	{
		rl_on_new_line();
		rl_redisplay();
		ft_putstr_fd("  \b\b", 2);
	}
	else
		ft_putstr_fd("^\\Quit: 3\n", 2);
}

static void	signal_handler(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
		handle_sigint(pid);
	else if (signo == SIGQUIT)
		handle_sigquit(pid);
}

void	signal_handler_init(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	signal_waiting_for_new_shell(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
