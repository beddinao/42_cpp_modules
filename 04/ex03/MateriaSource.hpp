#pragma once
#include <iostream>
#include "IMateriaSource.hpp"

class		MateriaSource: public	IMateriaSource
{
    private:
        AMateria			*inventory[4];
        std::string			known_materias[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource( const MateriaSource & );
        MateriaSource &operator = ( const MateriaSource & );
        //>
        void	learnMateria( AMateria* );
        AMateria*	createMateria( std::string const & );
        //>
        int	sizeof_str( std::string , char );
};






