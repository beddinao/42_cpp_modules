SRC = main.cpp Span.cpp
FLAGS = -Wall -Wextra -Werror #-std=c++98
OBJ = $(SRC:.cpp=.o)
NAME = span

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp	Span.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
