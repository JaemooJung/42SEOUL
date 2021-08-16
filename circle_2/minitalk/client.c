#include "minitalk.h"

int arg_error()
{
	printf("usage : [pid] [message]");
	return (1);
}

void send_message(int pid, char *str)
{
	if (*str == '1')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (arg_error());
	else
		send_message(atoi(argv[1]), argv[2]);
	return (0);
}
