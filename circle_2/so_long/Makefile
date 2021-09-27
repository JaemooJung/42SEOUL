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

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make all -C libft/

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIB)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	
re: clean all