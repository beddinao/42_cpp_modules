#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int a=0;a<4;a++)
        inventory[a] = NULL,
	  known_materias[a] = "";
}

MateriaSource::~MateriaSource()
{
    for (int a=0;a<4;a++)
        if (inventory[a])
	  delete	inventory[a];
}

MateriaSource::MateriaSource( const MateriaSource &_M )
{
    *this = _M;
}

MateriaSource	&MateriaSource::operator = ( const MateriaSource &_M )
{
    for (int a=0;a<4;a++)
    {
        _M.inventory[a] ?
	  inventory[a] = _M.inventory[a]
	  : inventory[a] = NULL;
    }
    return (*this);
}

/// // /

int	MateriaSource::sizeof_str( std::string s, char end )
{
    int			a=0;
    while (s[a] && s[a] != end)
        a++;
    return (a);
}

void	MateriaSource::learnMateria( AMateria *_m )
{
    int			a=0;
    while (inventory[a] && a<4)
        a++;
    //std::cout << "MateriaSource: ";
    if (a==4)
        std::cout << "can only learn 4 Materias\n";
    else if (_m)
    {
        inventory[a] = _m;
        known_materias[a] = _m->getType();
        /*std::cout << "learned new stuff: " << known_materias[a];
        a = 0;
        while (sizeof_str(known_materias[a], '\0') > 0
	      || !known_materias[a].compare(_m->getType()))
	  a++;
        if (a < 4)
	  known_materias[a] = _m->getType();*/
    }
    else
        std::cout << "not a valid materia\n";
}

AMateria	*MateriaSource::createMateria( std::string	const &type )
{
    for (int a=0;a<4;a++)
        if (!type.compare(known_materias[a]))
	  return (inventory[a]->clone());
    return (0);
}
