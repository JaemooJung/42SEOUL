#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "ft_printf.h"

void char_test3(char **str)
{
	(*str)++;
	(*str)++;
	printf("3 : %s\n", *str);
}

void char_test2(char **str)
{
	(*str)++;
	printf("2 : %s\n", *str);
	char_test3(str);
}

void char_test(char *str)
{
	printf("1 : %s\n", str);
	char_test2(&str);
	printf("4 : %s\n", str);
}

int main(void)
{
	
	//printf("int : |%.5d|\n", 4242);
	//printf("unsigned int : |%.3u|\n", 1234567891);

	
	//printf("ptr : |%p|\n", "HELLO");
	//printf("16 : |%30x|\n", 16);
	//printf("%% : |%10%|\n");
	//int a = printf("%s\n", NULL);
	//printf("%d\n", a);

	//char *test = malloc(sizeof(char) * 100);
	//test = "Hello, world";
	//char_test(test);
	printf("----------------------printf-------------------------------------------\n");
	int real_s = printf("str : |%s|\n", "hello world");
	printf("ft_s rtn = %d\n", real_s);
	int real_c = printf("char : |%-20.20c|%-4c|%-7c|\n", 'C', 'B', 'A');
	printf("real rtn = %d\n", real_c);
	printf("-------------------ft_printf-------------------------------------------\n");
	int ft_s = ft_printf("str : |%s|\n", "hello world");
	printf("ft_s rtn = %d\n", ft_s);
	int ft_c = ft_printf("char : |%-20.20c|%-4c|%-7c|\n", 'C', 'B', 'A');
	printf("ft_c rtn = %d\n", ft_c);
}

