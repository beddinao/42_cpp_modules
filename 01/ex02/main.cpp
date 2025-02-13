#include <iostream>

int	main()
{
	std::string	_string = "HI THIS BRAIN";
	std::string	*stringPTR = &_string;
	std::string	&stringREF = _string;

	// //// //	memory addresses
	//
	std::cout << 		&_string
		<< std::endl << stringPTR
		<< std::endl << &stringREF 
		<< std::endl;

	std::cout << std::endl;

	// ////		values
	//
	std::cout << 		_string
		<< std::endl << *stringPTR
		<< std::endl << stringREF
		<< std::endl;
}
