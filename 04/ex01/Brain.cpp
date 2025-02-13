#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain( const	Brain &_b )
{
    *this = _b;
    std::cout << "Brain copy constructor" << std::endl;
}

Brain	&Brain::operator = ( const Brain &_b )
{
    for (int a=0;a<100;a++)
        ideas[a] = _b.ideas[a];
    std::cout << "Brain copy-assignment operator" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain is destructed" << std::endl;
}
