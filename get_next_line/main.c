#include "get_next_line.h"
#include <stdio.h>

int main(void)
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
	return (0);
}