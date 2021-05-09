#include <unistd.h>

static void		ft_putnbr(int n, int fd)
{
	if (n > 9)
		ft_putnbr(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	ft_putnbr(n, fd);
}