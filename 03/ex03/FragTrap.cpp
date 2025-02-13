#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor is called" << std::endl;
}

FragTrap::FragTrap( std::string n_name )
{
    	name = n_name;
	hit_p = 100;
	energy_p = 100;
	attack_damage = 30;
	std::cout << "FragTrap name constructor is called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor is called" << std::endl;
}

FragTrap::FragTrap ( const FragTrap &_s )
{
	*this = _s;
	std::cout << "FragTrap copy constructor is called" << std::endl;
}

FragTrap		&FragTrap::operator = ( const FragTrap &_s )
{
	name = _s.name;
	hit_p = _s.hit_p;
	energy_p = _s.energy_p;
	attack_damage = _s.attack_damage;
	std::cout << "FragTrap copy assignment operator is called" << std::endl;
	return (*this);
}

void	FragTrap::attack( const std::string &target )
{
	std::cout << "FragTrap " << name;
	if (energy_p && hit_p)
		std::cout << " attack " << target << ", causing " << attack_damage << (attack_damage ? " points of damage\n" : "/nothing\n"),
		    energy_p -= 1;
	else
		std::cout << ": not enough energy/hit points for attack\n";
}

void			FragTrap::highFivesGuys()
{
	std::cout << "a positive high fives request" << std::endl;
}
