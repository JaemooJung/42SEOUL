NAME 		=	zombieHorde
CC 			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f

FILES 		=	main.cpp \
				Zombie.cpp \
				ZombieHorde.cpp

SRCS		=	$(FILES)
OBJS		=	$(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all
