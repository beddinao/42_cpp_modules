#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void		Harl::debug( void ){
	std::cout << "[DEBUG]";
}

void		Harl::info( void ){
	std::cout << "[INFO]";
}

void		Harl::warning( void ){
	std::cout << "[WARNING]";
}

void		Harl::error( void ){
	std::cout << "[ERROR]";
}

void		Harl::complain( std::string level )
{
	std::string		levels_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void			(Harl::*levels_PTR[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			a = 0;

	while (a < 4)
	{
		if (level == levels_str[a])
			(this->*levels_PTR[a])(),
			std::cout << " LEVEL COMPLAIN" << std::endl;
		a++;
	}
}
