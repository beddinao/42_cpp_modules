#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	name(name) {
		weapon = NULL;
	};

void	HumanB::setWeapon(Weapon &new_weapon){
	weapon = &new_weapon;
}

void	HumanB::attack( void )
{
	if (weapon)
		std::cout << name << " attacks with their "
			<< weapon->getType() << std::endl;
	else
		std::cout << name << " still does not have a weapon"
			<< std::endl;
}
