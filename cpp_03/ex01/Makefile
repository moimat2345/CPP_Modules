# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 17:20:35 by mateon            #+#    #+#              #
#    Updated: 2026/07/21 17:52:56 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCR = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ = $(SCR:.cpp=.o)

NAME = claptrap

CXX = c++

HPP = ClapTrap.hpp ScavTrap.hpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HPP)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

phony: all clean fclean re