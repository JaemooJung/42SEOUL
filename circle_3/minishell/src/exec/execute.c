/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:42:28 by hakim             #+#    #+#             */
/*   Updated: 2022/03/16 16:22:27 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_child_proc(t_info *info, char **chunk)
{
	char	**envp;
	int		builtin;
	int		(*builtins[8])(char **, t_list *);

	envp = to_vector(info->env);
	if (envp == NULL)
		exit(EXIT_FAILURE);
	if (info->pipeexists)
	{
		close(info->pipe[0]);
		if (dup2(info->pipe[1], STDOUT_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
	}
	builtins_init(builtins);
	builtin = classify_builtin(chunk[0]);
	if (builtin != NONE)
		exit(builtins[builtin](chunk, info->env));
	else if (chunk[0][0] == '.' && chunk[0][1] == '/'
		&& execve(chunk[0], chunk, envp) == -1)
		exit(125 + ft_print_error(chunk[0], NULL, "Permission denied"));
	execve(info->fullpath, chunk, envp);
	if (execve(chunk[0], chunk, envp) == -1)
		exit(126 + ft_print_error("command not found", NULL, chunk[0]));
	return (SUCCESS);
}

static int	do_parent_proc(char *cmd, pid_t pid, t_info *info)
{
	int	status;

	if (info->pipeexists)
	{
		close(info->pipe[1]);
		if (dup2(info->pipe[0], STDIN_FILENO) == -1)
			return (ft_print_error("Dup didn't work!", NULL, NULL));
	}
	if ((ft_strlen(cmd) == ft_strlen("./minishell"))
		&& ft_strncmp(cmd, "./minishell", 11) == 0)
		signal_waiting_for_new_shell();
	waitpid(pid, &status, 0);
	if (WTERMSIG(status) != 0)
	{
		if (WTERMSIG(status) == 2)
			printf("^C\n");
		info->exit_status = 128 + WTERMSIG(status);
	}
	else
		info->exit_status = WEXITSTATUS(status);
	signal_handler_init();
	if (info->pipeexists)
		close(info->pipe[0]);
	return (SUCCESS);
}

static int	lets_exec(t_info *info, char **chunk)
{
	pid_t	pid;

	if (info->fullpath == NULL)
		return (FAILURE);
	pid = fork();
	if (pid == -1)
		return (ft_print_error("You've got broken fork...", NULL, NULL));
	if (pid == 0)
		do_child_proc(info, chunk);
	do_parent_proc(chunk[0], pid, info);
	return (info->exit_status);
}

int	builtin_or_not(t_list *content, t_info *info)
{
	char	**chunk;
	int		stat;
	int		builtin;
	int		(*builtins[8])(char **, t_list *);

	if (content == NULL)
		return (SUCCESS);
	ft_lstadd_back(&content, info->remainder);
	info->remainder = NULL;
	chunk = to_vector(content);
	if (chunk == NULL)
		return (FAILURE);
	builtins_init(builtins);
	builtin = classify_builtin(chunk[0]);
	if (builtin != NONE && info->wasthereanypipe == false)
		stat = builtins[builtin](chunk, info->env);
	else
		stat = lets_exec(info, chunk);
	info->pipeexists = false;
	free(chunk);
	return (stat);
}
