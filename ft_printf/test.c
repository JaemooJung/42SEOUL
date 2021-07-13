#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	//printf("----------------------printf-------------------------------------------\n");
	//int real_s = printf("str : |%020.10s|\n", "hello");
	//printf("real_s rtn = %d\n", real_s);
	//int real_c = printf("char : |%020.10c|\n",  'A');
	//printf("real rtn = %d\n", real_c);
	//int real_d = printf("int : |%-20.10d|\n", -1);
	//printf("real_d rtn = %d\n", real_d);
	//printf("-------------------ft_printf-------------------------------------------\n");
	//int ft_s = ft_printf("str : |%020.10s|\n", "hello");
	//printf("ft_s rtn = %d\n", ft_s);
	//int ft_c = ft_printf("char : |%020.10c|\n", 'C');
	//printf("ft_c rtn = %d\n", ft_c);
	int ft_d = ft_printf("int : |%-20.10d|\n", -1);
	char *str = (char *)malloc(10);
	//printf("ft_d rtn = %d\n", ft_d);
}

