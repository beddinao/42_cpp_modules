#include "ScalarConverter.hpp"
#include <stdlib.h>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter &S ) {
	*this = S;
}

ScalarConverter	&ScalarConverter::operator = ( const ScalarConverter &S )
{
	(void)S;
	return (*this);
}

void	print_( float F, int is_precise )
{
	char	c[2] = {static_cast<char>(F), '\0'};

	std::cout << "char: " << ((c[0] < 127 && c[0] >= 32) ? c : !is_precise ? "impossible" : "non_displayable") 
		<< std::endl << "int: ";
	if (is_precise) std::cout << static_cast<int>(F);
	else std::cout << "imposible";
	std::cout << std::endl << "float: " << F << ((is_precise < 2) ? "f" : ".0f") << std::endl
		<< "double: " << static_cast<double>(F) << ((is_precise < 2) ? "" : ".0") << std::endl;
}

void	what_scalarTypes( char* s )
{
	char	*str = s;
	int	res = 2;

	while (*str == ' ' || *str == '-' || *str == '+')
		str++;
	if (!strncmp(str, "inf", 3) || !strncmp(str, "nan", 3))
		res = 0;
	else
	{
		if ((*str >= 'a' && *str <= 'z')
			|| (*str >= 'A' && *str <= 'Z'))
			return print_(  static_cast<float>(*str) , res);
		while (*str <= '9' && *str >= '0')
			str++;
		if (*str == '.')
			res = (*(++str) && *str != '0') ? 1 : res;
		return print_( atof(s), res );
	}
	print_( static_cast<float>(res ? atoi(s) : atof(s)), res);
}

void	ScalarConverter::convert( const void* s )
{
	what_scalarTypes((char*)s);
}
