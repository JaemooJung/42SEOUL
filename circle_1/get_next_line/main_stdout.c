#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *line;

	int fd = 0;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
}