NAME 		=	diamondTrap
CC 			=	c++
CFLAGS		=	-Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98
RM			=	rm -f

FILES 		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp

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

re:
	make fclean
	make all