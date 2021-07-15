# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 16:04:08 by jaemjung          #+#    #+#              #
#    Updated: 2021/07/15 21:08:05 by jaemoojung       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcus
RM = rm -f

FUNCS =			ft_printf.c \
				print_c_and_s.c \
				print_num.c \
				print_num_utils.c \

BONUS_FUNCS =	ft_printf_bonus.c \
				print_c_and_s_bonus.c \
				print_num_bonus.c \
				print_num_utils_bonus.c \

SRCS		= $(FUNCS)
BONUS_SRCS	= $(BONUS_FUNCS)

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	
re: clean all
