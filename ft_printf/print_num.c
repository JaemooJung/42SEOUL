#include "ft_printf.h"

char	*make_buffer(int i, t_opts *opts)
{
	if (opts->prec)
	{
	
	}
	else
		return (ft_itoa(i));
}

int	print_d(int i, t_opts *opts)
{
	char *buff;
	char blk;

	if (opts->zero)
		blk = '0';
	else
		blk = ' ';
	buff = make_buffer(i, opts);
}