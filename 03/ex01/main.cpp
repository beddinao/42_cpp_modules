#include "ScavTrap.hpp"

int		main()
{
	ScavTrap			scav1("robot_A");
	ScavTrap			scav2("robot_B");

	std::cout << std::endl;
	while (scav2.getHit_p())
	{
		scav1.attack(scav2.getName());
		scav2.takeDamage(scav1.getAttack_damage());
		if (!scav2.getHit_p())
			scav2.beRepaired(scav1.getAttack_damage());
		std::cout << std::endl;
	}
	scav1.guardGate();
	std::cout << std::endl;
}
