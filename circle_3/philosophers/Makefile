NAME 		=	philo
NAME_BONUS	=	philo_bonus

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LIB			=	libft/libft.a
RM			=	rm -f

FILES 		=	main.c \
				error_handler.c \
				check_args.c \
				init_philo.c \
				philo_functions.c \
				philo_functions_2.c \
				time_functions.c

BONUS_FILES	=	main_bonus.c \

SRC_DIR		=	./sources/
BONUS_DIR	=	./sources_bonus/
INC_DIR		=	./includes

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))
BONUS_SRCS	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

LIBFT		=	libft.a

.PHONY: all clean fclean re bonus

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

$(LIBFT):
	make all -C libft/

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LIB)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) -o $@ $^ $(LIB)

bonus: $(LIBFT) $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make fclean -C libft
	
re: clean all