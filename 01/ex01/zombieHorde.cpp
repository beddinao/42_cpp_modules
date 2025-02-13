#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie		*Horde = new Zombie[N];
	int				a = 0;

	while (a < N)
		Horde[a++].setName(name);
	return (Horde);
}
