#pragma once
#include <iostream>

class		ICharacter;

class		AMateria
{
    	protected:
	    std::string			type;
    	public:
	    AMateria();
	    virtual ~AMateria();
	    AMateria( const AMateria & );
	    AMateria &operator = ( const AMateria & );
	    AMateria ( std::string const & );
	    //>
	    std::string	const & getType() const;
	    virtual AMateria* clone() const = 0;
	    virtual void	use ( ICharacter & );
};
