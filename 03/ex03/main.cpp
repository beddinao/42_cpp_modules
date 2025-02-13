#include "DiamondTrap.hpp"

int		main()
{
    std::cout << "\ndiamond construction: " << std::endl;
    DiamondTrap		di2("diamond");

    std::cout << "\nscav construction: " << std::endl;
    ScavTrap		scav("scav");

    std::cout << "\nfrag construction: " << std::endl;
    FragTrap		frag("frag");

    std::cout << "\nHit points: \n"; 
    std::cout << "diamondtrap: " << di2.getHit_p() << ", fragtrap: " << frag.getHit_p() <<  ", scavtrap: " << scav.getHit_p() << std::endl;
    std::cout << "\nenergy points: \n";
    std::cout << "diamondtrap: " << di2.getEnergy_p() << ", fragtrap: " << frag.getEnergy_p() << ", scavtrap: " << scav.getEnergy_p() << std::endl;
    std::cout << "\nattack damage: \n";
    std::cout << "diamondtrap: " << di2.getAttack_damage() << ", fragtrap: " << frag.getAttack_damage() << ", scavtrap: " << scav.getAttack_damage() << std::endl;
    std::cout << "\nattacking: \n";
    di2.attack("a victim");
    std::cout << "\nidentity check: \n";
    di2.whoAmI();
    std::cout << "\ncopy check: \n";
    DiamondTrap	di1( di2 );
    std::cout << std::endl;
    std::cout << "name: " << di1.getName() << ", " << di2.getName() << "; attack_damage: " << di1.getAttack_damage() << ", " << di2.getAttack_damage() << std::endl;
    std::cout << std::endl;
}
