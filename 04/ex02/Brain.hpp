#pragma once
#include <iostream>

class		Brain
{
	public:
	    Brain();
	    Brain( const Brain & );
	    Brain	&operator	= ( const Brain & );
	    ~Brain();
	    std::string		ideas[100];
};
