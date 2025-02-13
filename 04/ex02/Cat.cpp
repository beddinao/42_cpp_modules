#include "Cat.hpp"

Cat::Cat()
{
    brain = new Brain;
    type = "Cat";
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat( const Cat &_c )
{
    *this = _c;
    std::cout << "Cat copy constructor" << std::endl;
}

Cat	&Cat::operator = ( const Cat &_c )
{
    type = _c.type;
    brain = new Brain(*_c.brain);
    std::cout << "Cat copy assignment operator" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete	brain;
    std::cout << "Cat is destructed" << std::endl;
}

void	Cat::makeSound() const
{
    std::cout << "cats sound" << std::endl;
}

std::string	Cat::getIdea(unsigned int index) const
{
    return  index < 100 ? this->brain->ideas[index] : "";
}

void		Cat::setIdea(std::string idea, unsigned int index)
{
    if (index < 100)
	    this->brain->ideas[index] = idea;
    else
        std::cout << type << "'s brain: can't keep them that far\n";
}
