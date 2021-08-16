#include "minitalk.h"

void sig_handler(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
		printf("1 received\n");
	else if (signo == SIGUSR2)
		printf("0 received\n");
}

int display_pid()
{
	int pid;

	pid = getpid();
	printf("pid : %d\n", pid);
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
