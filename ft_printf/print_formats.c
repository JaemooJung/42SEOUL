#include "ft_printf.h"

int print_c(char c, t_opts *opts)
{
	int i;

	i = 0;
	if (opts->zero)
	{
		while (i++ < opts->width - 1)
			ft_putchar_fd('0', 1);
		ft_putchar_fd(c, 1);		
	}
	else if (opts->minus)
	{
		ft_putchar_fd(c, 1);
		while (i++ < opts->width - 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (i++ < opts->width - 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	if (opts->width > 0)
		return (opts->width);
	return (1);
}