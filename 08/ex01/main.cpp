#include "Span.hpp"

int main()
{
	std::cout << "test 1: Big Operation" << std::endl;
	//
	unsigned int		size = 10000;
	Span			sp = Span(size);
	int			min = -10000;
	int			max = 10000;
	
	std::srand(time(NULL));
	
	for (size_t i = 0; i < size; i++)
		sp.addNumber(std::rand() % ( max - min ) + min);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	//
	/////
	std::cout << "\ntest 2: addRange()" << std::endl;
	size = 3;
	Span			sp_2 = Span(size);
	sp_2.addNumber(10);
	std::vector<int>		vec;
	vec.push_back(9);
	vec.push_back(8);
	sp_2.addRange(vec);
	sp_2.print();
	//
	/////
	std::cout << "\ntest 3: given one" << std::endl;
	Span			sp_3 = Span(5);

	sp_3.addNumber(6);
	sp_3.addNumber(3);
	sp_3.addNumber(17);
	sp_3.addNumber(9);
	sp_3.addNumber(11);
	
	std::cout << sp_3.shortestSpan() << std::endl;
	std::cout << sp_3.longestSpan() << std::endl;
	//
	/////
	std::cout << "\ntest 4: adding beyond the given size" << std::endl;
	size = 1;
	Span			sp_4 = Span(size);

	sp_4.addNumber(3);
	try {
		sp_4.addNumber(2);
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
}

