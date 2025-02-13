#pragma  once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class		Cure: public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure ( const Cure &_i );
        Cure &operator = ( const Cure &_i );
	//>
        AMateria *clone() const;
        void	use( ICharacter & );
};
		 
