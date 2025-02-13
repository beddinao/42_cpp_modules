#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class		Cat:	public Animal
{
    Brain			*brain;
    public:
        Cat();
        Cat( const Cat & );
        Cat	&operator = ( const Cat & );
        ~Cat();
        //>
        void	makeSound() const;
        //>
        void	setIdea(std::string, unsigned int);
        std::string	getIdea(unsigned	int index) const;
};
