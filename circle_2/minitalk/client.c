#include "minitalk.h"

void	sent_to_server(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

void	change_to_bit_and_send(int pid, char c, int bit_len)
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

void	send_message(int pid, char *str)
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

int	err_hander(int err)
{
	if (err == 1)
		ft_printf("usage : [pid] [message to send]\n");
	return (err);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (err_hander(1));
	ft_printf("client pid : [%d]\n", getpid());
	send_message(ft_atoi(argv[1]), argv[2]);
	ft_printf("message sended to server pid [%d]\n", ft_atoi(argv[1]));
}
