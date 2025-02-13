#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class			Dog: public	Animal
{
    Brain				*brain;
    public:
	Dog();
	Dog( const Dog & );
	Dog	&operator = ( const Dog & );
	~Dog();
	//>
	void		makeSound() const;
	//>
	void		setIdea(std::string, unsigned int);
	std::string	getIdea( unsigned int ) const;
};
