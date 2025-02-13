#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
	: hit_p(10), energy_p(10), attack_damage(0)
{
	std::cout << "default ClapTrap constructor is called\n";
}

ClapTrap::ClapTrap( std::string name )
	: name(name), hit_p(10), energy_p(10), attack_damage(0)
{
	std::cout << "ClapTrap name constructor is called\n";
}

ClapTrap::ClapTrap ( const ClapTrap &clap )
{
	*this = clap;
	std::cout << "ClapTrap copy constructor is called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called\n";
}

ClapTrap	&ClapTrap::operator = ( const ClapTrap &clap )
{
	name = clap.name;
	hit_p = clap.hit_p;
	energy_p = clap.energy_p;
	attack_damage = clap.attack_damage;
	std::cout << "ClapTrap copy assignment operator is called\n";
	return (*this);
}

///////////////////>
///
std::string	ClapTrap::getName() const
{
	return (name);
}

unsigned int	ClapTrap::getAttack_damage() const
{
	return (attack_damage);
}

unsigned int	ClapTrap::getHit_p() const
{
	return (hit_p);
}

unsigned int	ClapTrap::getEnergy_p() const
{
	return (energy_p);
}
///
/////////////////////

void	ClapTrap::attack( const std::string &target )
{
	std::cout << "ClapTrap " << name;
	if (energy_p && hit_p)
		std::cout << " attack " << target << ", causing " << attack_damage << (attack_damage ? " points of damage\n" : "/nothing\n"),
		    energy_p -= 1;
	else
		std::cout << ": not enough energy/hit points for attack\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap ";
	if (hit_p >= amount)
		std::cout << name << ": got damaged losing " << amount << " health\n",
			hit_p -= amount;
	else
		std::cout << name << ": got damaged but dont have enough health to take it all\n",
			hit_p = 0;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap ";
	if (energy_p && hit_p)
		std::cout << name << ": just " << (energy_p == 1 ? "spent its last energy point " : "repaired ") << "adding " << amount << " health\n",
			hit_p += amount,
			      energy_p -= 1;
	else
		std::cout << name << ": not enough energy/hit points for repairment\n";
}



