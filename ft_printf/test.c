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
	printf("char : |%*c|\n", 10, 'A');
	//printf("int : |%.5d|\n", 4242);
	//printf("unsigned int : |%.3u|\n", 1234567891);

	//printf("str : |%30.5s|\n", "hello world");
	//printf("ptr : |%p|\n", "HELLO");
	//printf("16 : |%30x|\n", 16);
	//printf("%% : |%10%|\n");
	//int a = printf("%s\n", NULL);
	//printf("%d\n", a);

	//char *test = malloc(sizeof(char) * 100);
	//test = "Hello, world";
	//char_test(test);

	printf("-------------------ft_printf----------------\n");
	ft_printf("char : |%*c|\n", 10, 'A');
}

