# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateon <mateon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/26 03:23:49 by mateon            #+#    #+#              #
#    Updated: 2026/10/07 08:34:40 by mateon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re