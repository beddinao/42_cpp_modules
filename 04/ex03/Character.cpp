#include "Character.hpp"

Character::Character()
{
    for (int a=0;a<4;a++)
        inventory[a] = NULL;
}

Character::Character( std::string name )
    : name(name)
{
    for (int a=0;a<4;a++)
        inventory[a] = NULL;
}

Character::~Character()
{
    for (int a=0;a<4;a++)
        if (inventory[a])
	  delete	inventory[a];
}

Character::Character( const Character &_C )
{
    *this = _C;
}

Character	&Character::operator = ( const Character &_C )
{
    name = _C.name;
    for (int a=0;a<4;a++)
    {
        if (inventory[a])
	  delete	inventory[a];
        _C.inventory[a] ?
	  inventory[a] = _C.inventory[a]->clone()
        		: inventory[a] = NULL;
    }
    return (*this);
}

/// / /// //

void	Character::equip( AMateria *_m )
{
    int			a = 0;
    while (inventory[a] && a < 4)
        a++;
    if (a==4)
        std::cout << name << ": inventory is full\n";
    else if (_m)
        inventory[a] = _m;
    else
        std::cout << name << ": not a valid materia " << _m << '\n';
}

void	Character::unequip( int index )
{
    if (index < 0 || index > 3)
        std::cout << name << ": not a valid index to access inventory\n";
    else if (inventory[index])
        inventory[index] = NULL;
    else
	std::cout << "inventory at " << index << " is empty\n";
}

void	Character::use( int index, ICharacter	&target )
{
    if (inventory[index])
        inventory[index]->use(target);
    else
        std::cout << "Can't use Materia at slot " << index << std::endl;
}

std::string const	&Character::getName() const
{
    return (name);
}
