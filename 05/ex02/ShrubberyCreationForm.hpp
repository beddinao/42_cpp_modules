#pragma once
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	std::string		target;
	public:
		ShrubberyCreationForm( std::string );
		ShrubberyCreationForm( const ShrubberyCreationForm & );
		ShrubberyCreationForm	&operator = ( const ShrubberyCreationForm & );
		~ShrubberyCreationForm();
		//>
		std::string	getTarget() const;
		void		execute( Bureaucrat const & ) const;
};

