NAME 		=	so_long

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIB			=	libft/libft.a
RM			=	rm -f

FUNCS 		=	so_long.c \
				parse_map.c \
				parse_map_check_wall.c \
				error.c

SRCS		= $(FUNCS)

OBJS		= $(SRCS:.c=.o)

LIBFT		= libft.a

MLX			= libmlx.dylib

.PHONY: all clean fclean re

all: $(MLX) $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./minilibx -c -o $@ $<

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