#include <iostream>
#include "Weapon.hpp"

class		HumanB
{
	std::string			name;
	Weapon				*weapon;
	public:
		HumanB(std::string name);
		void		attack( void );
		void		setWeapon(Weapon &new_weapon);
};
