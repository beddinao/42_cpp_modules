#pragma once
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class		Intern
{
	std::string	forms_strs[3];
	public:
		Intern();
		Intern( const Intern & );
		Intern	&operator = ( const Intern & );
		~Intern();
		//>
		AForm*	makeForm( std::string, std::string );
};
