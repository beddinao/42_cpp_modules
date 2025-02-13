#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &_a )
{
    *this = _a;
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator = ( const WrongAnimal &_a )
{
    type = _a.type;
    std::cout << "WrongAnimal copy assignment operator" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal is destructed" << std::endl;
}

void	WrongAnimal::makeSound() const {}

std::string		WrongAnimal::getType() const
{
    return (type);
}
