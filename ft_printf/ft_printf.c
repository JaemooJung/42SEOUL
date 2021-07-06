#include "ft_printf.h"

int	print_f_str(char **f_str, t_opts *opts, va_list ap)
{
	if (opts->type == 'c')
		return (print_c(va_arg(ap, int), opts));
	else if (opts->type == 's')
	{}
	else if (opts->type == 'd' || opts->type == 'i')
	{}
	else if (opts->type == 'u')
	{}
	else if (opts->type == 'x')
	{}
	else if (opts->type == 'X')
	{}
	return (0);
}

void	get_width_prec(char **f_str, t_opts *opts, va_list ap)
{
	if (**f_str == '*')
	{
		if (opts->prec)
			opts->prec_scale = va_arg(ap, int);
		else
			opts->width = va_arg(ap, int);
	}
	else if (ft_isdigit(**f_str))
	{
		if (opts->prec) // prec이 켜져있으면 prec_scale로, 아니면 width로.
			opts->prec_scale = (opts->prec_scale * 10) + (**f_str - '0');
		else
			opts->width = (opts->width * 10) + (**f_str - '0');
	}
}

int	start_parsing(char **f_str, va_list ap)
{
	t_opts	*opts;

	opts = ft_calloc(1, sizeof(t_opts)); // 옵션 초기화 #### TODO: free() => [X]
	if (!opts) // 말록 실패 시 가드
		return (-1);
	while (**f_str != '\0' && !(ft_strchr(TYPES, **f_str))) // 타입이 나오기 전까지 돌면서 옵션들 체크
	{
		if (**f_str == '-')
			opts->minus = 1;
		else if (**f_str == '.')
			opts->prec = 1;
		else if (**f_str == '0' && opts->width == 0 && opts->prec != 1)
			opts->zero = 1;
		else if (ft_isdigit(**f_str) || **f_str == '*')
			get_width_prec(f_str, opts, ap); // TODO : 이부분에서 width 와 prec 체크하는 함수
		(*f_str)++;
	}
	if (opts->minus) // - 옵션이 켜진 경우 제로는 무조건 무시되므로 이 경우 제거
		opts->zero = 0;
	opts->type = **f_str;// 포맷 타입 저장
	(*f_str)++;
	return (print_f_str(f_str, opts, ap));// 이제 파싱한 내용을 바탕으로 포맷 스트링 출력
}

int	ft_printf(const char *f_str, ...)
{
	int		out_len;
	va_list	ap;

	va_start(ap, f_str);
	out_len = 0;
	while (*f_str != '\0') // 주어진 포맷스트링을 돌며
	{
		if (*f_str != '%') // % 기호가 없으면 그냥 출력
		{
			ft_putchar_fd(*f_str, 1);
			f_str++;
			out_len++;
		}
		else // 있으면 포맷스트링 출력을 위해 파싱
		{
			f_str++; // 일단 % 다음으로 포인터를 넘겨주고
			start_parsing((char **)&f_str, ap); // 파싱 시작
		}
	}
	return (out_len);
}
