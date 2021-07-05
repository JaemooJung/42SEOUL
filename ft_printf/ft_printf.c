#include "ft_printf.h"

int ft_printf(const char *f_str, ...)
{
	int out_len;
	va_list ap;

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
	}
	return (out_len);
}