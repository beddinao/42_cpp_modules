#pragma once
#include <iostream>

class		ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter( const ScalarConverter & );
		ScalarConverter	&operator = ( const ScalarConverter & );
		virtual ~ScalarConverter() =0;
		//>
		static void	convert( const void* );
};
