SRC = main.cpp ClapTrap.cpp
#FLAGS = -Wall -Wextra -Werror -std=c++98
FLAGS = 
OBJ = $(SRC:.cpp=.o)
NAME = claptrap

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp ClapTrap.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
