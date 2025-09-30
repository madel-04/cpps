CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = identify

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
