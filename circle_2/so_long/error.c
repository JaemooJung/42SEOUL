#include "so_long.h"

void error_handler(char *error_message, int error_code)
{
	ft_printf(error_message);
	exit(error_code);
}