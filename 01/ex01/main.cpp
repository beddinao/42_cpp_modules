#include "Zombie.hpp"

int main()
{
	int				N = 3;
	Zombie	*fr = zombieHorde(N, "a Zombie with his fellas");

	// ////		directly calling announce
	while (N--)
		fr[N].announce();
	std::cout << std::endl;

	/// // /	destructors announce
	delete [] fr;
}
