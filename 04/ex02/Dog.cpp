#include "Dog.hpp"

Dog::Dog()
{
    brain	= new Brain;
    type = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog( const Dog &_d )
{
    *this = _d;
    std::cout << "Dog copy constructor" << std::endl;
}
Dog	&Dog::operator = ( const Dog &_d )
{
    type = _d.type;
    brain = new Brain(*_d.brain);
    std::cout << "Dog copy assignment operator" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete	brain;
    std::cout << "Dog is destructed" << std::endl;
}

void		Dog::makeSound() const
{
    std::cout << "barking.." << std::endl;
}

std::string	Dog::getIdea(unsigned int index) const
{
    return  (index < 100) ? this->brain->ideas[index] : "";
}

void	Dog::setIdea(std::string	idea, unsigned int index)
{
    if (index < 100)
	    this->brain->ideas[index] = idea;
    else
        std::cout << type << "'s brain: can't keep them that far\n";
}
