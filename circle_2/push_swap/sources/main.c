#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		error_handler();
	check_arguments_and_append(argc, argv);
}
