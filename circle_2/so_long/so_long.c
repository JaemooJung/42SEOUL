#include "so_long.h"

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;

	width = 400;	
	height = 400;
	mlx_ptr = mlx_init();	//mlx 할당 실패할 경우 NULL반환
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Title"); 
					// 할당된 mlx에 너비. 높이를 갖는 윈도우 창 생성.
	mlx_loop(mlx_ptr);
}