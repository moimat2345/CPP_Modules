#
# CPP - Module 01 - ex03 : Unnecessary violence
# Makefile
#

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

NAME = violence

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
