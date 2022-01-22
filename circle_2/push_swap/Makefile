NAME 		=	push_swap

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LIB			=	libft/libft.a
RM			=	rm -f

FILES 		=	main.c \
				check_arguments.c \
				doubly_linked_list_utils.c \
				error_handler.c \
				init_stack.c \
				stack_utils.c \
				stack_operation_1.c \
				stack_operation_2.c \
				stack_operation_3.c \
				sort.c \
				sort_under_three.c \
				sort_under_five.c \
				sort_under_five_utils.c \
				sort_functions.c \
				sort_utils.c

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