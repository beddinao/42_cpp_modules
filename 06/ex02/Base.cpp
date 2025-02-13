#include "Base.hpp"

Base::~Base() {};

Base		*generate( void )
{
	std::srand(time(NULL));
	Base	*all[3] = {new A, new B, new C};
	int	r_number = std::rand() % 3;

	for (int i=0;i < 3; i++)
	{
		if (i != r_number)	delete	all[i];
		else	std::cout << "<-- just generated a class of Type: Base::"
			<< static_cast<char>('A' + i) << std::endl << std::endl;
	}
	return (all[r_number]);
}

void		identify( Base *p )
{
	Base	*all[3] = {new A, new B, new C};
	for (int i=0; i < 3; i++)
	{
		if (typeid(*p) == typeid(*all[i]))
			std::cout << "--> the pointer is of type Base::"
				<< static_cast<char>('A' + i) << std::endl;
		delete	all[i];
	}
}

void		identify( Base &p )
{
	std::cout << "--> it is of the Base::";
	if (typeid(A) == typeid(p)) std::cout << "A";
	else if (typeid(B) == typeid(p)) std::cout << "B";
	else if (typeid(C) == typeid(p)) std::cout << "C";
	std::cout << " type" << std::endl;
}
