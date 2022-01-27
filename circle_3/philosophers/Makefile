NAME 		=	philo

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LIB			=	libft/libft.a
RM			=	rm -f

FILES 		=	main.c \

SRC_DIR		=	./sources/
INC_DIR		=	./includes

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))
OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft.a


.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

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