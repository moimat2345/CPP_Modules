#
# CPP - Module 01 - ex06 : Harl filter
# Makefile
#

SRC = main.cpp Harl.cpp

OBJ = $(SRC:.cpp=.o)

NAME = harlFilter

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Harl.hpp

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
