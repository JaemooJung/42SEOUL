NAME_SRV = server
NAME_CLI = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcus
RM = rm -f

SRV_FUNCS = server.c error.c
CLI_FUNCS = client.c error.c

SRV_SRCS = $(SRV_FUNCS)
CLI_SRCS = $(CLI_FUNCS)

SRV_OBJS = $(SRV_SRCS:.c=.o)
CLI_OBJS = $(CLI_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME_SRV) $(NAME_CLI)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME_SRV): $(SRV_OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME_SRV)
	$(AR) $@ $^

$(NAME_CLI): $(CLI_OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME_CLI)
	$(AR) $@ $^

clean:
	$(RM) $(SRV_OBJS) $(CLI_OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME_SRV) $(NAME_CLI)
	make fclean -C libft
	
re: fclean all