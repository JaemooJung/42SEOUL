#include "ft_memmove.c"
#include <stdio.h>

int main(void)
{
	char str[50] = "aossuepr8.tistory.com";
	
	puts(str);
	ft_memmove(str + 21, str + 17, 4);
	puts(str);
}