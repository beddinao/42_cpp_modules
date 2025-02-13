#pragma once
#include <string>
#include <iostream>

class		Weapon
{
	std::string			type;
	public:
		Weapon(std::string type);
		const	std::string	&getType( void );
		void	setType(std::string new_type);
		~Weapon( void );
};
