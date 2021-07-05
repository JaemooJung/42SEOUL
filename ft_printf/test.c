#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
	ft_printf("Good Morning\n");
	printf("int : |%8d|\n", 12345);
	printf("char : |%8c|\n", 67);
	printf("str : |%8s|\n", "hello world");
	printf("float : |%0100f|\n", 123.456);
}