NAME 		=	philo
NAME_BONUS	=	philo_bonus

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

FILES 		=	main.c \
				error_handler.c \
				check_args.c \
				ft_atoi.c \
				ft_putstr_fd.c \
				init_philo.c \
				philo_functions.c \
				philo_functions_2.c \
				time_functions.c

BONUS_FILES	=	main_bonus.c \
				check_args_bonus.c \
				error_handler_bonus.c \
				ft_atoi_bonus.c \
				ft_itoa_bonus.c \
				ft_putstr_fd_bonus.c \
				init_philo_bonus.c \
				philo_functions_bonus.c \
				philo_functions_2_bonus.c \
				time_functions_bonus.c \
				check_philo_bonus.c \
				wait_die_or_finish_bonus.c

SRC_DIR		=	./sources/
BONUS_DIR	=	./sources_bonus/
INC_DIR		=	./includes

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))
BONUS_SRCS	=	$(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)


.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) -o $@ $^

bonus: $(LIBFT) $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: clean all