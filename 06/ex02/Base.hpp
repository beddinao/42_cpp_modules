#pragma once
#include <iostream>

class		Base
{
	public:
		virtual ~Base() =0;
};

class		A: public Base {};
class		B: public Base {};
class		C: public Base {};

Base	*generate( void );
void	identify( Base* );
void	identify( Base& );
