#pragma once
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class	Character: public ICharacter
{
    private:
        AMateria		*inventory[4];
        std::string		name;
    public:
        Character();
        ~Character();
        Character( std::string );
        Character( const Character & );
        Character &operator = ( const Character & );
        //>
        std::string	const	&getName() const;
        void	equip( AMateria* );
        void	unequip( int );
        void	use( int , ICharacter & );
};

