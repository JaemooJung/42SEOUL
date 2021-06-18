#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *line; 
	int ret;

	int fd = open("./test.txt", O_RDONLY);
	while((ret = get_next_line(fd, &line)) > 0)
	{
		printf("return : %d\n",ret);
		printf("line : %s\n",line);
		free(line);
	}
	printf("return : %d\n",ret);
	printf("line : %s\n",line);
	free(line);

	int fd2 = open("./test_2.txt", O_RDONLY);
	while((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("return : %d\n",ret);
		printf("line : %s\n",line);
		free(line);
	}
	printf("return : %d\n",ret);
	printf("line : %s\n",line);
	free(line);

	printf("%d", OPEN_MAX);

	printf("read lines from stdin");
	while (1)
	{
		ret = get_next_line(0, &line);
		printf("return : %d\n",ret);
		printf("line : %s\n",line);
		free(line);
	}
	return (0);
}