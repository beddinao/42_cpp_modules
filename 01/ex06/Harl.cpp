#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void		Harl::debug( void ){
	std::cout << "\n[DEBUG]" << std::endl;
}

void		Harl::info( void ){
	std::cout << "\n[INFO]" << std::endl;
}

void		Harl::warning( void ){
	std::cout << "\n[WARNING]" << std::endl;
}

void		Harl::error( void ){
	std::cout << "\n[ERROR]" << std::endl;
}

void		Harl::complain( std::string level, int min_level )
{
	std::string		levels_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void			(Harl::*levels_PTR[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			a = 0;

	while (a < 4)
	{
		if (a >= min_level && level == levels_str[a])
			(this->*levels_PTR[a])(),
				std::cout << " LEVEL COMPLAIN\n" << std::endl;
		a++;
	}
}
