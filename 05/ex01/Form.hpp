#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class		Bureaucrat;

class		Form
{
	const std::string		name;
	bool			is_signed;
	const int			sign_grade;
	const int			exec_grade;
	public:
		Form();
		Form ( const std::string, const int, const int);
		Form( const Form & );
		Form	&operator = ( const Form & );
		~Form();
		//>
		class		GradeTooHighException : public std::exception {
			const char	*what() const throw();
		};
		class		GradeTooLowException : public std::exception {
			const char	*what() const throw();
		};
		//>
		const std::string	get_name() const;
		int		get_sign_grade() const;
		int		get_exec_grade() const;
		bool		get_is_signed() const;
		//>
		void		beSigned( const Bureaucrat & );
};

std::ostream		&operator << ( std::ostream &, const Form & );
