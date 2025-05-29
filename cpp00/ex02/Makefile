# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 20:27:49 by madel-va          #+#    #+#              #
#    Updated: 2025/05/14 20:27:49 by madel-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX       = g++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98
SRCS      = tests.cpp Account.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = account

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
