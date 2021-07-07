#include "ft_printf.h"

int	print_c(char c, t_opts *opts)
{
	int	i;

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

int	print_s(char *s, t_opts *opts)
{
	int len;
	int i;
	char *tmp_s;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	i = 0;
	/*
	경우의수 : width < len : 그냥 스트링 출력
			width > len : width - len 만큼 ' ' 출력한 후 스트링 출력
			
			precision이 켜진경우 -> precision의 갯수 만큼 스트링 출력

			- 옵션이 켜진경우 -> 따로 처리 할 것. 
	*/
	if (opts->prec) // prec 이 켜진 경우
	{
		// width 가 prec 보다 작은 경우 
		while (i < opts->prec_scale && i < len)
		{
		}

		// width 가 prec 보다 큰 경우
	}
	else // prec 없는 경우
	{
		if (opts->width <= len)
		{
			ft_putstr_fd(s, 1);
			return (len);
		}
		else
		{
			while (i < (opts->width - len))
			{
				ft_putchar_fd(' ', 1);
				i++;
			}
			ft_putstr_fd(s, 1);
			return (opts->width);
		}
	}
	return (0);
}
