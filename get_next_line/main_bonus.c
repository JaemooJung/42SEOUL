#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd1;
	int fd2;
	int fd3;
	char *line;

	fd1 = open("./test.txt", O_RDONLY);
	fd2 = open("./test_2.txt", O_RDONLY);
	fd3 = open("./test_3.txt", O_RDONLY);
	for (int i = 0; i < 4; i++)
	{
		get_next_line(fd1, &line);
		printf("%s\n", line);
		get_next_line(fd2, &line);
		printf("%s\n", line);
		get_next_line(fd3, &line);
		printf("%s\n", line);
	}
}