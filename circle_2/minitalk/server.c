#include "minitalk.h"

static void	print_client_info(siginfo_t *info)
{
	ft_printf(" [message from pid %d]\n", info->si_pid);
}

static void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit_len;

	if (info->si_pid <= 100)
		return ;
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
		print_client_info(info);
		return ;
	}
	if (bit_len == 0)
		ft_putchar_fd(c, 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	ft_printf("server pid : [%d] | ready to receive message.\n", getpid());
	if (sigaction(SIGUSR1, &action, 0) != 0)
		error_hander("sigaction failure");
	if (sigaction(SIGUSR2, &action, 0) != 0)
		error_hander("sigaction failure");
	while (1)
		pause();
	return (0);
}
