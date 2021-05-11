# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 16:04:08 by jaemjung          #+#    #+#              #
#    Updated: 2021/05/11 15:47:41 by jaemoojung       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FUNCS		=	ft_memset \
				ft_bzero \
				ft_memcpy \
				ft_memccpy \
				ft_memmove \
				ft_memchr \
				ft_memcmp \
				ft_strlen \
				ft_strlcpy \
				ft_strlcat \
				ft_strchr \
				ft_strrchr \
				ft_strnstr \
				ft_strncmp \
				ft_atoi \
				ft_isalpha \
				ft_isdigit \
				ft_isalnum \
				ft_isascii \
				ft_isprint \
				ft_toupper \
				ft_tolower \
				ft_calloc \
				ft_strdup \
				ft_substr \
				ft_strjoin \
				ft_strtrim \
				ft_split \
				ft_itoa \
				ft_strmapi \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_putendl_fd \
				ft_putnbr_fd \

BONUS_FUNCS	=	ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap

SRCS_DIR	= ./
OBJS_DIR	= ./

SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FUNCS)))
BONUS_SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_FUNCS)))

OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FUNCS)))
BONUS_OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS_FUNCS)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: clean all

.PHONY: bonus all clean fclean re
