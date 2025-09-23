CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = iter

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
