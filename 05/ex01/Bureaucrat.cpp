#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat( std::string name, int new_grade )
	: name (name)
{
	this->update_grade( new_grade );
}

Bureaucrat::Bureaucrat( const Bureaucrat &_copy )
{
	*this = _copy;
}

Bureaucrat	&Bureaucrat::operator = ( const Bureaucrat &_copy )
{
	this->grade = _copy.grade;
	return (*this);
}

const	char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High\n";
}

const	char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low\n";
}

const	std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::update_grade( int new_grade )
{
	try {
		if (new_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (new_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		grade = new_grade;
	}
	catch (int i) { }
}

void	Bureaucrat::increment_grade()
{
	this->update_grade( grade - 1 );
}

void	Bureaucrat::decrement_grade()
{
	this->update_grade( grade + 1 );
}

void	Bureaucrat::signForm( Form &form ) const
{
	std::cout << name;
	try {
		form.beSigned(*this);
		std::cout << " signed " << form.get_name()
			<< std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cout << " couldn\'t sign " << form.get_name()
			<< " because: " << e.what();
	}
}

std::ostream	&operator << ( std::ostream &c, const Bureaucrat &B )
{
	c << B.getName() << ", bureaucrat grade " << B.getGrade() << ".\n";
	return (c);
}
