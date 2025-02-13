#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main()
{
	FragTrap			frag1("robot_A");
	FragTrap			frag2("robot_B");

	std::cout << std::endl;
	while (frag2.getHit_p())
	{
		frag1.attack(frag2.getName());
		frag2.takeDamage(frag1.getAttack_damage());
		if (!frag2.getHit_p())
			frag2.beRepaired(frag1.getAttack_damage());
		std::cout << std::endl;
	}
	frag1.highFivesGuys();
	std::cout << std::endl;
}
