#include "ft_printf_bonus.h"

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

static int	process_s_width(char *s, int len, t_opts *opts, char blk)
{
	int	i;

	i = 0;
	if (opts->minus)
	{
		ft_putstr_fd(s, 1);
		while (i < (opts->width - len))
		{
			ft_putchar_fd(blk, 1);
			i++;
		}
	}
	else
	{
		while (i < (opts->width - len))
		{
			ft_putchar_fd(blk, 1);
			i++;
		}
		ft_putstr_fd(s, 1);
	}
	return (opts->width);
}

static int	print_fstr_with_width(char *s, t_opts *opts, char blk)
{
	int	rtn;

	if (opts->prec)
	{
		s = ft_substr(s, 0, opts->prec_scale);
		rtn = process_s_width(s, ft_strlen(s), opts, blk);
		ft_free(s);
	}
	else
	{
		if (opts->width <= ft_strlen(s))
		{
			ft_putstr_fd(s, 1);
			rtn = ft_strlen(s);
		}
		else
			rtn = process_s_width(s, ft_strlen(s), opts, blk);
	}
	return (rtn);
}

static int	print_fstr_without_width(char *s, t_opts *opts)
{
	int	rtn;

	if (opts->prec)
	{
		s = ft_substr(s, 0, opts->prec_scale);
		ft_putstr_fd(s, 1);
		rtn = ft_strlen(s);
		ft_free(s);
	}
	else
	{
		ft_putstr_fd(s, 1);
		rtn = ft_strlen(s);
	}
	return (rtn);
}

int	print_s(char *s, t_opts *opts)
{
	int		rtn;
	char	blk;

	if (!s)
		s = "(null)";
	if (opts->zero)
		blk = '0';
	else
		blk = ' ';
	if (opts->width)
		rtn = print_fstr_with_width(s, opts, blk);
	else
		rtn = print_fstr_without_width(s, opts);
	return (rtn);
}
