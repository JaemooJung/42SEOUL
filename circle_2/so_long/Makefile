NAME 		=	so_long

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIB			=	libft/libft.a
RM			=	rm -f

FILES 		=	so_long.c \
				error.c \
				parse_map/parse_map.c \
				parse_map/parse_map_check_wall.c \
				

SRC_DIR		=	./sources/
INC_DIR		=	./includes

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft.a

MLX			=	libmlx.dylib

.PHONY: all clean fclean re

all: $(MLX) $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./minilibx -I$(INC_DIR) -c -o $@ $<

$(LIBFT):
	make all -C libft/

$(MLX):
	make all -C minilibx/

$(NAME): $(OBJS)
	$(CC) -L ./minilibx -lmlx -framework OpenGL -framework AppKit -o $@ $^ $(LIB)
	install_name_tool -change libmlx.dylib ./minilibx/libmlx.dylib $(NAME)
clean:
	$(RM) $(OBJS)
	make clean -C libft
	make clean -C minilibx

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean -C minilibx
	
re: clean all