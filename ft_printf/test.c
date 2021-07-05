#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
	ft_printf("Good Morning\n");

	printf("int : |%.d|\n", 12345);
	printf("unsigntd int : |%.3u|\n", 1234567891);
	printf("char : |%c|\n", 'b');
	printf("str : |%20s|\n", "hello world");
	printf("ptr : |%p|\n", "HELLO");
	printf("16 : |%-30x|\n", 16);
}