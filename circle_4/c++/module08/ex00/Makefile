NAME 		=	easyfind
CXX 		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98
RM			=	rm -f

FILES 		=	main.cpp

SRCS		=	$(FILES)
OBJS		=	$(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all