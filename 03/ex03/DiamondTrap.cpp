#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string new_name )
	:	 ClapTrap(new_name + "_clap_name")
{
    this->name = new_name;
    std::cout << "DiamondTrap name constructor is called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor is called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &_d )
{
    *this = _d;
    std::cout << "DiamondTrap copy constructor is called" << std::endl;
}

std::string	DiamondTrap::getName() const
{
    return (name);
}

DiamondTrap	&DiamondTrap::operator = ( const DiamondTrap &_d )
{
    name = _d.name;
    hit_p = _d.hit_p;
    energy_p = _d.energy_p;
    attack_damage = _d.attack_damage;
    std::cout << "DiamondTrap copy assignment operator is called" << std::endl;
    return (*this);
}

void	DiamondTrap::attack( const std::string &target )
{
    ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name : " << getName() << std::endl;
    std::cout << "ClapTrap name : " << ClapTrap::getName() << std::endl;
}

