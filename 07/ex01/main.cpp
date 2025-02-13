#include "Iter.hpp"


void	fn_1( std::string	a )
{
	std::cout << "fn_1: " << a << std::endl;
}


template	<typename T>
void	fn_2( T	o )
{
	std::cout << "fn_2: " << (o - 1) << std::endl;
}

int	main()
{
	std::string	arr_1[2] = { "F", "S" };
	Iter(arr_1, 2, fn_1);


	int		arr_2[3] = { 1, 3, 2 };
	Iter(arr_2, 3, fn_2<int>);
}

