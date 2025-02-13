#include "ClapTrap.hpp"



int		main()
{
	ClapTrap		clap_1("robot_A");
	ClapTrap		clap_2("robot_B");
	
	clap_1 = clap_1;

	std::cout << "clap 1 name: " << clap_1.getName() << std::endl;
	//std::cout << "clap 2 name: " << clap_2.getName() << std::endl;
}
