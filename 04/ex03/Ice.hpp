#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class		Ice: public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice (const Ice &_i);
        Ice &operator = (const Ice &_i);
	//>
	AMateria*	clone() const;
	void	use(ICharacter	& target);
};
