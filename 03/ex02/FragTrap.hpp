#include <iostream>
#include "ClapTrap.hpp"


class			FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap( std::string );
		~FragTrap();
		FragTrap ( const FragTrap & );
		FragTrap		&operator = ( const FragTrap & );
		void			attack( const std::string	& );
		void			highFivesGuys( void );
};
