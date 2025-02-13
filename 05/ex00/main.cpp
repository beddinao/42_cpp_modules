#include "Bureaucrat.hpp"

int		main()
{
	// initializing with higher grade
	try {
		Bureaucrat		BUU("b_1", 0);
		std::cout << BUU;
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what();
	}

	// incrementing grade beyonde
	Bureaucrat		BUU("b_2", 3);
	try {
		for ( int i = 100; i; i-- )
		{
			BUU.increment_grade();
			std::cout << BUU;
		}
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what();
	}

	// decrementing grade beyonde
	Bureaucrat		B_2("b_3", 140);
	try {
		for ( int i = 20; i; i-- )
			B_2.decrement_grade(),
				std::cout << B_2;
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what();
	}
}
