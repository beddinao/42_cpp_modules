#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor" << std::endl;
}

void	Animal::makeSound() const {}

Animal::Animal( const Animal &_a )
{
    *this = _a;
    std::cout << "Animal copy constructor" << std::endl;
}

Animal	&Animal::operator = ( const Animal &_a )
{
    type = _a.type;
    std::cout << "Animal copy-assignment operator" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal is destructed" << std::endl;
}

std::string		Animal::getType() const
{
    return (type);
}
