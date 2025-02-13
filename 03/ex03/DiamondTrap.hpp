#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class			DiamondTrap : public FragTrap, public ScavTrap
{
    private:
	std::string				name;
    public:
	DiamondTrap();
	DiamondTrap( std::string );
	~DiamondTrap();
	DiamondTrap( const DiamondTrap & );
	DiamondTrap				&operator = ( const DiamondTrap & );
	void					attack( const std::string	& );
	void					whoAmI();
	//>
	std::string				getName() const;
};

