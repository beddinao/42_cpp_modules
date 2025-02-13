#include "Cat.hpp"

Cat::Cat()
{
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
    std::cout << "Cat copy assignment operator" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat is destructed" << std::endl;
}

void	Cat::makeSound() const
{
    std::cout << "cats sound" << std::endl;
}
