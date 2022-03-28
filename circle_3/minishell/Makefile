NAME 		=	minishell

CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RL_LINK		=	-L/Users/hakim/.brew/opt/readline/lib -lreadline
RL_INCLUDE	=	-I/Users/hakim/.brew/opt/readline/include
#RL_LINK	=	-lreadline -L/usr/local/opt/readline/lib
#RL_INCLUDE	=	-I/usr/local/opt/readline/include
# RL_LINK		=	-L/opt/homebrew/opt/readline/lib -lreadline
# RL_INCLUDE	=	-I/opt/homebrew/opt/readline/include
RM			=	rm -f

FILES 		=	main.c \
				parse_user_input/parse_user_input.c \
				parse_user_input/split_input.c \
				parse_user_input/lexer.c \
				parse_user_input/parser.c \
				parse_user_input/parser_funcs.c \
				parse_user_input/parser_utils.c \
				parse_user_input/parser_utils_2.c \
				parse_user_input/tree_utils.c \
				parse_user_input/compare_and_join_env.c \
				parse_user_input/expand_env.c \
				parse_user_input/expand_env_utils.c \
				builtin/cd.c \
				builtin/echo.c \
				builtin/env.c \
				builtin/exit.c \
				builtin/export_append.c \
				builtin/export.c \
				builtin/pwd.c \
				builtin/unset.c \
				builtin/builtin_utils.c \
				utils/ft_split.c \
				utils/list_1.c \
				utils/list_2.c \
				utils/utils_1.c \
				utils/utils_2.c \
				utils/utils_3.c \
				utils/utils_4.c \
				utils/utils_5.c \
				our_env.c \
				signal_handler.c \
				exec/execute.c \
				exec/path.c \
				exec/pipe_n_dup.c \
				exec/redir_utils.c \
				exec/redir.c \
				exec/run_tokens.c \
				exception_collector.c \

SRC_DIR		=	./src/
INC_DIR		=	./inc

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))
OBJS		=	$(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) $(RL_INCLUDE) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(RL_LINK) -o $@ $^
	stty -echoctl

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all
