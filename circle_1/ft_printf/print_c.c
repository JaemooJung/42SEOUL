#include "ft_printf.h"

int	print_c(char c, t_opts *opts)
{
	int		i;
	char	blk;

	i = 0;
	if (opts->zero)
		blk = '0';
	else
		blk = ' ';
	if (opts->minus)
	{
		ft_putchar_fd(c, 1);
		while (i++ < opts->width - 1)
			ft_putchar_fd(blk, 1);
	}
	else
	{
		while (i++ < opts->width - 1)
			ft_putchar_fd(blk, 1);
		ft_putchar_fd(c, 1);
	}
	if (opts->width > 0)
		return (opts->width);
	return (1);
}
