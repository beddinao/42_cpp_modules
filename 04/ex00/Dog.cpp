#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog( const Dog &_d )
{
    *this = _d;
    std::cout << "Dog copy constructor" << std::endl;
}
Dog	&Dog::operator = ( const Dog &_d )
{
    type = _d.type;
    std::cout << "Dog copy assignment operator" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog is destructed" << std::endl;
}

void	Dog::makeSound() const
{
    std::cout << "bark" << std::endl;
}
