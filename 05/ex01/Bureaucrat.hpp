#pragma once
#include "Form.hpp"
#include <iostream>

class		Form;

class		Bureaucrat
{
	const std::string			name;
	int				grade;
	public:
		Bureaucrat();
		Bureaucrat( std::string, int );
		Bureaucrat( const Bureaucrat & );
		Bureaucrat	&operator = ( const Bureaucrat & );
		~Bureaucrat();
		//>
		const std::string	getName() const;
		int 	getGrade() const;
		void		increment_grade();
		void		decrement_grade();
		//>
		class	GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		//>
		void	update_grade( int );
		//>
		void	signForm( Form & ) const;
};

std::ostream		&operator << ( std::ostream &, const Bureaucrat & );
