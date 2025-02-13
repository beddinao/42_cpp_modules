#include "ScavTrap.hpp"


ScavTrap::ScavTrap()
	:	ClapTrap()
{
	hit_p = 100;
	energy_p = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap( std::string name )
	:	ClapTrap(name)
{
	hit_p = 100;
	energy_p = 50;
	attack_damage = 20;
	std::cout << "ScavTrap name constructor is called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called" << std::endl;
}

ScavTrap::ScavTrap ( const ScavTrap &_s )
{
	*this = _s;
	std::cout << "ScavTrap copy constructor is called" << std::endl;
}

ScavTrap		&ScavTrap::operator = ( const ScavTrap &_s )
{
	name = _s.name;
	hit_p = _s.hit_p;
	energy_p = _s.energy_p;
	attack_damage = _s.attack_damage;
	std::cout << "ScavTrap copy assignment operator is called" << std::endl;
	return (*this);
}

void	ScavTrap::attack( const std::string &target )
{
	std::cout << "ScavTrap " << name;
	if (energy_p && hit_p)
		std::cout << " attack " << target << ", causing " << attack_damage << (attack_damage ? " points of damage\n" : "/nothing\n"),
		    energy_p -= 1;
	else
		std::cout << ": not enough energy/hit points for attack\n";
}

void			ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
