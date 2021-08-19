#include "minitalk.h"

static void	sent_to_server(int pid, int bit)
{
	if (bit == 1)
	{
		if (kill(pid, SIGUSR1) < 0)
			error_hander("signal transmission failure. check your pid again");
	}
	else if (bit == 0)
	{
		if (kill(pid, SIGUSR2) < 0)
			error_hander("signal transmission failure. check your pid again");
	}
	usleep(250);
}

static void	change_to_bit_and_send(int pid, char c, int bit_len)
{
	if (c == 0)
	{
		while (bit_len < 8)
		{
			sent_to_server(pid, 0);
			bit_len++;
		}
		return ;
	}
	else
	{
		change_to_bit_and_send(pid, c / 2, ++bit_len);
		sent_to_server(pid, c % 2);
	}
}

static void	send_message(int pid, char *str)
{
	int	end_conv_marker;

	end_conv_marker = 8;
	while (*str)
	{
		change_to_bit_and_send(pid, *str, 0);
		str++;
	}
	while (end_conv_marker--)
		sent_to_server(pid, 1);
}

static int	check_pid(char *pid)
{
	while (*pid)
	{
		if (ft_isdigit(*pid) == 0)
			return (0);
		pid++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error_hander("usage : ./client [pid] [message to send]");
	else if (check_pid(argv[1]) == 0)
		error_hander("wrong pid. pid only contains digits");
	ft_printf("client pid : [%d]\n", getpid());
	send_message(ft_atoi(argv[1]), argv[2]);
	ft_printf("message sended to server pid [%d]\n", ft_atoi(argv[1]));
}
