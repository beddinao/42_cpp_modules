#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	leaks_fun()
{
    system("leaks character");
}

int main()
{
    	//atexit(leaks_fun);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("you");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	
	ICharacter	*character = new Character("bad character");
	//>
	//
	IMateriaSource	*mas = new MateriaSource();
	mas->learnMateria(new Ice());

	AMateria	*new_materia = mas->createMateria("a non");
	if (!new_materia)
	    new_materia = mas->createMateria("cure");
	if (!new_materia)
	    new_materia = mas->createMateria("ice");

	character->equip(new_materia);
	character->use(0, *character);

	AMateria	*sec = new_materia->clone();

	delete character;

	std::cout << sec->getType() << std::endl;

	delete mas;
	delete sec;
}
