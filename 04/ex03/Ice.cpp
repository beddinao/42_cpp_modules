#include "Ice.hpp"


Ice::Ice()
{
    type = "ice";
}

Ice::~Ice() {}

Ice::Ice( const Ice &_i )
{
    *this = _i;
}

Ice	&Ice::operator = ( const Ice &_i )
{
    type = _i.type;
    return (*this);
}

AMateria	*Ice::clone() const
{
    AMateria			*temp = new Ice(*this);
    return (temp);
}

void	Ice::use(ICharacter	&target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
        << std::endl;
}
