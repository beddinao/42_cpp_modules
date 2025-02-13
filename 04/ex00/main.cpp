#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void		leaks_fun()
{
    system("leaks		animal");
}

int	main()
{
    	//atexit(leaks_fun);
    	std::cout << "\nAnimal construction: " << std::endl;
	const 		Animal* meta = new Animal();

	std::cout << "\nDog construction: " << std::endl;
	const 		Animal* j = new Dog();

	std::cout << "\nCat construction: " << std::endl;
	const 		WrongAnimal* i = new WrongCat();

	std::cout << "\ntypes: \n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << "\nmakeSound() function: \n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;


	delete meta;
	delete i;
	delete j;
}
