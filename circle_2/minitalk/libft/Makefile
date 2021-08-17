# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 16:04:08 by jaemjung          #+#    #+#              #
#    Updated: 2021/08/18 01:09:07 by jaemoojung       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcus
RM = rm -f

FUNCS 		=	ft_printf.c \
				print_c.c \
				print_s.c \
				print_num.c \
				print_num_utils.c \

SRCS		= $(FUNCS)
OBJS		= $(SRCS:.c=.o)


.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	
re: clean all
