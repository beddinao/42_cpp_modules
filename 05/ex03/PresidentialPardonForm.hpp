#pragma once
#include "AForm.hpp"
#include <iostream>

class	PresidentialPardonForm: public AForm
{
	std::string			target;
	public:
		PresidentialPardonForm( std::string );
		PresidentialPardonForm( const PresidentialPardonForm & );
		PresidentialPardonForm	&operator = ( const PresidentialPardonForm & );
		~PresidentialPardonForm();
		//>
		std::string	getTarget() const;
		void		execute( Bureaucrat const & ) const;
};
