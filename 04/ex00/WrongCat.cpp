#include "WrongCat.hpp"


WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat &_c )
{
    *this = _c;
    std::cout << "WrongCat copy constructor" << std::endl;
}
WrongCat	&WrongCat::operator = ( const WrongCat &_c )
{
    type = _c.type;
    std::cout << "WrongCat copy assignment operator" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat is destructed" << std::endl;
}

void	WrongCat::makeSound() const
{
    std::cout << "WrongCats sound" << std::endl;
}
