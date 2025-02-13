#include "Cure.hpp"

Cure::Cure()
{
    type = "cure";
}

Cure::~Cure() {}

Cure::Cure( const Cure &_i )
{
    *this = _i;
}

Cure	&Cure::operator = ( const Cure &_i )
{
    type = _i.type;
    return (*this);
}

AMateria	*Cure::clone() const
{
    AMateria		*temp = new Cure(*this);
    return (temp);
}

void	Cure::use( ICharacter	&target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
