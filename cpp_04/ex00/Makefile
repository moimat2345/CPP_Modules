# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 18:31:47 by mateon            #+#    #+#              #
#    Updated: 2026/07/23 19:15:45 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp src/Animal.cpp src/Cat.cpp src/Dog.cpp src/WrongAnimal.cpp src/WrongCat.cpp

OBJ = $(SRCS:.cpp=.o)

INCLUDE = -I include

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animal

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
