#include "../includes/so_long.h"

void error_handler(char *error_message)
{
	if (!error_message)
	{
		printf("Error\n%s\n", strerror(errno));
		exit(errno);
	}
	else
	{
		printf("Error\n%s\n", error_message);
		exit(1);
	}
}