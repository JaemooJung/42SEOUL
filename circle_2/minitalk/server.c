#include "minitalk.h"

void sig_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char c;
	static int bit_len;

	if (--bit_len == -1)
	{
		bit_len = 7;
		c = 0;
	}
	if (signo == SIGUSR1)
		c |= (1 << bit_len);
	else if (signo == SIGUSR2)
		c &= ~(1 << bit_len);
	if (c == 255)
	{	
		ft_putchar_fd('\n', 1);
		return ;
	}
	if (bit_len == 0)
		ft_putchar_fd(c, 1);
}

int display_pid()
{
	char *pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd("pid : ", 1);
	ft_putstr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	free(pid);
	return (0);
}

int main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	display_pid();
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		;
	return (0);
}
