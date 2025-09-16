NAME = DiamondTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wno-shadow -Wshadow -std=c++98

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


# -Wshadow: This compiler flag enables warnings when a variable declaration
 # shadows another variable (e.g., a local variable with the same name as a
 # member variable or parameter). It helps catch bugs due to name hiding.

#-Wno-shadow: This disables those shadowing warnings, even if shadowing
 # occurs.