#include "ft_printf.h"

int	print_f_str(char **f_str, t_opts *opts, va_list ap)
{
	int	f_str_len;

	if (opts->type == 'c')
		f_str_len = print_c(va_arg(ap, int), opts);
	else if (opts->type == 's')
		f_str_len = print_s(va_arg(ap, char *), opts);
	else if (opts->type == 'd' || opts->type == 'i')
		f_str_len = print_d(va_arg(ap, int), opts);
	else if (opts->type == 'u')
	{}
	else if (opts->type == 'x')
	{}
	else if (opts->type == 'X')
	{}
	else if (opts->type == 'p')
	{}
	free(opts);
	opts = NULL;
	return (f_str_len);
}

void	get_width_prec(char **f_str, t_opts *opts, va_list ap)
{
	if (opts->prec)
		opts->prec_scale = (opts->prec_scale * 10) + (**f_str - '0');
	else
		opts->width = (opts->width * 10) + (**f_str - '0');
}

int	start_parsing(char **f_str, va_list ap)
{
	t_opts	*opts;

	opts = ft_calloc(1, sizeof(t_opts));
	if (!opts)
		return (-1);
	while (**f_str != '\0' && !(ft_strchr(TYPES, **f_str)))
	{
		if (**f_str == '-')
			opts->minus = 1;
		else if (**f_str == '.')
			opts->prec = 1;
		else if (**f_str == '0' && opts->width == 0 && opts->prec != 1)
			opts->zero = 1;
		else if (ft_isdigit(**f_str))
			get_width_prec(f_str, opts, ap);
		(*f_str)++;
	}
	if (opts->minus)
		opts->zero = 0;
	opts->type = **f_str;
	(*f_str)++;
	return (print_f_str(f_str, opts, ap));
}

int	ft_printf(const char *f_str, ...)
{
	int		out_len;
	va_list	ap;

	va_start(ap, f_str);
	out_len = 0;
	while (*f_str != '\0')
	{
		if (*f_str != '%')
		{
			ft_putchar_fd(*f_str, 1);
			f_str++;
			out_len++;
		}
		else
		{
			f_str++;
			out_len += start_parsing((char **)&f_str, ap);
		}
	}
	return (out_len);
}