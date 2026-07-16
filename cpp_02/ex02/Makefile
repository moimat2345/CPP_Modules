# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/16 17:37:54 by mateon            #+#    #+#              #
#    Updated: 2026/07/16 18:03:09 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Fixed.cpp

INCLUDE = Fixed.hpp

OBJ = $(SRC:.cpp=.o)

NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re