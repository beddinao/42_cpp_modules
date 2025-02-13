#pragma once
#include <iostream>

class			ClapTrap
{
    	protected:
		std::string			name;
		unsigned int				hit_p;
		unsigned int				energy_p;
		unsigned int				attack_damage;
	public:
		ClapTrap();
		ClapTrap( std::string );
		ClapTrap( const ClapTrap & );
		ClapTrap	&operator = ( const ClapTrap & );
		~ClapTrap();
		//>
		void			attack( const std::string & );
		void			takeDamage( unsigned int );
		void			beRepaired( unsigned int );
		//>
		std::string		getName() const;
		unsigned int		getAttack_damage() const;
		unsigned int		getHit_p() const;
		unsigned int		getEnergy_p() const;
};
