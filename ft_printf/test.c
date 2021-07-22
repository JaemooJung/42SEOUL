#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	// int a = 10;

	// printf("----------------------printf-------------------------------------------\n");
	// int real_s = printf("str : |%020.10s|\n", "hello");
	// printf("real_s rtn = %d\n", real_s);
	// int real_c = printf("char : |%020.10c|\n",  'A');
	// printf("real rtn = %d\n", real_c);
	// int real_percent = printf("percent : |%.100%|\n");
	// printf("real_percent rtn = %d\n", real_percent);
	// int real_d = printf("int : |%30d|\n", 1234);
	// printf("real_d rtn = %d\n", real_d);
	// int real_x = printf("hex lc : |%-.20x|\n", -65535000000);
	// printf("real_x rtn = %d\n", real_x);
	// int real_X = printf("hex uc : |%-.20X|\n", -65535000000);
	// printf("real_x rtn = %d\n", real_X);
	// int real_p = printf("pointer : |%-0100p|\n", &a);
	// printf("real_p rnt = %d\n", real_p);
	// printf("-------------------ft_printf-------------------------------------------\n");
	// int ft_x = ft_printf("hex lc : |%x|\n", "hello");
	// printf("ft_x rtn = %d\n", ft_x);
	// int ft_X = ft_printf("hex uc : |%-.20X|\n", -6553500000);
	// printf("ft_x rtn = %d\n", ft_X);
	// int ft_p = ft_printf("pointer : |%-0100p|\n", &a);
	// printf("ft_p rnt = %d\n", ft_p);
	// int ft_s = ft_printf("str : |%020.10s|\n", "hello");
	// printf("ft_s rtn = %d\n", ft_s);
	// int ft_c = ft_printf("char : |%020.10c|\n", 'C');
	// printf("ft_c rtn = %d\n", ft_c);
	// int ft_percent = ft_printf("percent : |%.100%|\n");
	// printf("ft_percent rtn = %d\n", ft_percent);
	// int ft_d = ft_printf("int : |%30d|\n", 1234);
	// printf("ft_d rtn = %d\n", ft_d);
	// printf("-------------------combined--test--------------------------------------\n");
	// int test_ft = ft_printf("char : %020c|\n str : %030.1s|\n num : %030.1d|\n unsigned num : %-30u|\n hex : %-30x|\n pointer : %-30p|\n", 'A', NULL, 42, 4242, 4242, NULL);
	// int test_real = printf("char : %020c|\n str : %030.1s|\n num : %030.1d|\n unsigned num : %-30u|\n hex : %-30x|\n pointer : %-30p|\n", 'A', NULL, 42, 4242, 4242, NULL);
	// printf("ft_return = %d\n", test_ft);
	// printf("real_return = %d\n", test_real);
	printf("|%.p|\n", NULL);
	ft_printf("|%.p|\n", NULL);
}

