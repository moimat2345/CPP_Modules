#
# CPP - Module 01 - ex04 : Sed is for losers
# Makefile
#

SRC = main.cpp FileReplacer.cpp

OBJ = $(SRC:.cpp=.o)

NAME = replace

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = FileReplacer.hpp

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
