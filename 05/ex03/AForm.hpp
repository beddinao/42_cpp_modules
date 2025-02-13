#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class		Bureaucrat;

class		AForm
{
	const std::string		name;
	bool			is_signed;
	const int			sign_grade;
	const int			exec_grade;
	public:
		AForm();
		AForm ( const std::string, const int, const int);
		AForm( const AForm & );
		AForm	&operator = ( const AForm & );
		~AForm();
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
		void	beSigned( const Bureaucrat & );
		virtual void	execute( Bureaucrat const & ) const;
};

std::ostream		&operator << ( std::ostream &, const AForm & );
