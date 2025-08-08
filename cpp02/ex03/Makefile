# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madel-va <madel-va@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 00:00:00 by madel-va          #+#    #+#              #
#    Updated: 2025/08/07 00:00:00 by madel-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = objs

SOURCES = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re