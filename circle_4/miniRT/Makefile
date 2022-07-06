NAME 		=	miniRT

CC 			=	cc
CFLAGS		=	-Werror -Wall -Wextra
RM			=	rm -f

FILES 		=	main.c \
				error.c \
				trace/ray.c \
				trace/ray_hit_obj.c \
				trace/ray_hit_sp.c \
				trace/ray_hit_cy.c \
				trace/ray_hit_pl.c \
				trace/phong_lighting.c \
				scene/scene.c \
				scene/draw.c \
				scene/objects.c \
				scene/objects_utils.c \
				utils/utils.c \
				utils/utils_vec_operations.c \
				utils/utils_vec_operations_2.c \
				utils/utils_vec_operations_3.c \
				utils/mlx_utils.c \
				gnl/get_next_line_utils.c \
				gnl/get_next_line.c \
				parser/parser_figure.c \
				parser/parser_type.c \
				parser/parser_unique.c \
				parser/parser_utils.c \
				parser/parser_validation.c \
				parser/parser.c

SRC_DIR		=	./sources/
INC_DIR		=	./includes
MLX_DIR		=	./minilibx
LIBFT_DIR	=	./libft

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))

OBJS		=	$(SRCS:.c=.o)

MLX			=	libmlx.dylib

.PHONY: all clean fclean re

all: $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INC_DIR) -c -o $@ $<

$(MLX):
	make all -C $(MLX_DIR)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $@ $^
	install_name_tool -change libmlx.dylib $(MLX_DIR)/libmlx.dylib $(NAME)
clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	make clean -C minilibx

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	make clean -C minilibx
	
re: clean all