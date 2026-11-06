# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 18:40:00 by mateon            #+#    #+#              #
#    Updated: 2026/11/06 18:40:00 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
	  	ScalarConverter.cpp


OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re