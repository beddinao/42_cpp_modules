#include "Zombie.hpp"

Zombie	*newZombie(std::string		name)
{
	Zombie *zombie = new Zombie;

	zombie->setName(name);
	return (zombie);
}

void	randomChump(std::string	name)
{
	Zombie	   zombie;
	zombie.setName(name);
	zombie.announce();
}

int main()
{
	Zombie		*zombie_1 = newZombie("a Zombie on heap");
	zombie_1->announce();
	delete zombie_1;


	randomChump("a zombie on stack");
}
