SRC = main.cpp Character.cpp AMateria.cpp MateriaSource.cpp Ice.cpp Cure.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)
NAME = character

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp Character.hpp MateriaSource.hpp Ice.hpp Cure.hpp 
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
