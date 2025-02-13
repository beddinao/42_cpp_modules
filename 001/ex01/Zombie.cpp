#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){
	std::cout << name << ": is destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string new_name)
{
	name = new_name;
}
