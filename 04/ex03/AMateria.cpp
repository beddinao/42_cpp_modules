#include "AMateria.hpp"

AMateria::AMateria() {}
AMateria::~AMateria() {}
void	AMateria::use(ICharacter	&t)
{
    (void)t;
}

AMateria::AMateria( const AMateria &_am )
{
    *this = _am;
}
AMateria	&AMateria::operator = ( const AMateria &_am )
{
    type = _am.type;
    return (*this);
}
AMateria::AMateria( std::string	const &type )
    : type(type) {}

std::string const &AMateria::getType() const
{
    return (type);
}
