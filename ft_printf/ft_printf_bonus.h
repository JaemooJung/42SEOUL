#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

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
	int		prec_processed;
}			t_opts;

int			ft_printf(const char *f_str, ...);

int			print_c(char c, t_opts *opts);
int			print_s(char *s, t_opts *opts);
int			print_num(long long num, t_opts *opts);

char		*process_hex(long long num, t_opts *opts);

char		*process_negative(char *buff, t_opts *opts);
char		*process_negative_with_zero(char *buff, t_opts *opts);

void		ft_free(void *ptr);

#endif