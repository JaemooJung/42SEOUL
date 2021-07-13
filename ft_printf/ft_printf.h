#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPES "cspdiuxX%"

typedef struct s_opts
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		prec_scale;
	char	type;
	int		format_len;
}			t_opts;

int	ft_printf(const char *f_str, ...);

int print_c(char c, t_opts *opts);
int print_s(char *s, t_opts *opts);
int print_d(int i, t_opts *opts);

#endif