#include "Weapon.hpp"

Weapon::~Weapon() {}

Weapon::Weapon(std::string type):
	type(type) {}

const	std::string		&Weapon::getType( void )
{
	return (type);
}

void		Weapon::setType(std::string new_type)
{
	type = new_type;
}
