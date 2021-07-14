#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# include <stdio.h> // TODO : 최종적으로 지울 것.

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
	int		d_negative;
}			t_opts;

int			ft_printf(const char *f_str, ...);

int			print_c(char c, t_opts *opts);
int			print_s(char *s, t_opts *opts);
int			print_num(long long num, t_opts *opts);

char		*process_hex(long long num, t_opts *opts);

void		ft_free(void *ptr);

#endif