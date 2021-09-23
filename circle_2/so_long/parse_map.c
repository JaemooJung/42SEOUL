#include "so_long.h"

int parse_map(char *file_name)
{
	char **map;
	int map_fd;

	// 파일 이름이 없을 경우 에러리턴
	if (!file_name)
		return (1);
	printf("%s\n", file_name);
	char *check = ft_strrchr(file_name, '.');
	printf("%s\n", check);
	int a = ft_strncmp(check, ".ber", 4);
	printf("%d\n", a);

	//파일이름 확인하여 확장자가 .ber 형식이 아니라면 에러 리턴
	if (ft_strncmp(ft_strrchr(file_name, '.'), ".ber", 4) != 0)
		printf("wrong map file. wrong extension\n");

	//파일 오픈. 파일이 안열렸다면 에러 리턴.
	map_fd = open(file_name);
	if (map_fd < 0)
		return (1);
	//get_next_line으로 맵 받아와서 저장
	//맵 크기를 알아야 말록 가능 ... 시부랄
	// 한글자씩 읽어오며 저장? 어떻게 할까
	// 너무 무모한거같은데...
	


	//맵 체크 시작. 
	
	// 맵이 첫 번째 줄이 모두 1인지 체크
	// 맵 두번째 줄 부터 마지막까지 시작과 끝이 1인지 체크 하나라도 이상하면 에러
	// 맵 마지막 줄이 모두 1인지 체크 하나라도 이상하면 에러
	// 맵 마지막줄까지 한 줄이라도 첫 번째 줄의 길이와 다르면 에러 리턴.
	// 맵에 P와 E가 1개인지 체크. 2개 이상이라면 에러 리턴.
	// 맵에 C가 0개이면 에러 리턴.
	return (0);
}

int main(int argc, char **argv)
{
	parse_map(argv[1]);
	return (0);
}