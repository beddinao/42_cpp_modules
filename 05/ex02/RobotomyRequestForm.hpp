#pragma once
#include <iostream>
#include "AForm.hpp"

class		RobotomyRequestForm: public AForm
{
	std::string			target;
	public:
		RobotomyRequestForm( std::string );
		RobotomyRequestForm( const RobotomyRequestForm & );
		RobotomyRequestForm		&operator = ( const RobotomyRequestForm & );
		~RobotomyRequestForm();
		//>
		std::string	getTarget() const;
		void		execute( Bureaucrat const & ) const;
};
