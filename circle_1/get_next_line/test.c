#include <stdio.h>

int rtn1(int a)
{
	if (a)
		return 1;
	else
		return 0;
}

int main(void)
{
	if (!(rtn1(0)))
		printf("0 returned \n");
}