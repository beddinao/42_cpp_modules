#include "Serializer.hpp"


int main()
{
	Data	*a = new Data;
	a->text = "something";
	std::cout << "a: inserted data: " << a->text << std::endl;

	uintptr_t	serial_number = Serializer::serialize( a );
	std::cout << "\nobject unique serial number is: " << serial_number << std::endl;

	Data	*b = Serializer::deserialize( serial_number );
	std::cout << "\nb: outputed data:   " << b->text << std::endl;
	delete 	a;
}
