#include "Form.hpp"

Form::Form()
	: is_signed(false), sign_grade(150), exec_grade(150) {}
Form::~Form() {}

Form::Form ( std::string name, int new_sign_grade, int new_exec_grade)
	: name(name), is_signed(false), sign_grade(150), exec_grade(150)
{
	try {
		if (new_sign_grade < 1)
			throw Form::GradeTooHighException();
		else if (new_sign_grade > 150)
			throw Form::GradeTooLowException();
		int	*s_ptr = (int*)(&sign_grade);
		*s_ptr = new_sign_grade;
	}
	catch (int a) {}
	try {
		if (new_exec_grade < 1)
			throw Form::GradeTooHighException();
		else if (new_exec_grade > 150)
			throw Form::GradeTooLowException();
		int	*s_ptr = (int*)(&exec_grade);
		*s_ptr = new_exec_grade;
	}
	catch (int a) {}
}

Form::Form ( const Form &_copy )
	: sign_grade(_copy.get_sign_grade()), exec_grade(_copy.get_exec_grade())
{
	*this = _copy;
}

Form	&Form::operator = ( const Form &_copy )
{
	int	*sign_ptr = (int*)(&sign_grade);
	int	*exec_ptr = (int*)(&exec_grade);
	*sign_ptr = _copy.get_sign_grade();
	*exec_ptr = _copy.get_exec_grade();
	is_signed = _copy.is_signed;
	return (*this);
}

const	char*	Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too High\n";
}

const	char*	Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too Low\n";
}

void		Form::beSigned( const Bureaucrat &B )
{
	try {
		if (B.getGrade() > sign_grade)
			throw Form::GradeTooLowException();
		is_signed = true;
	}
	catch (int a) {}
}

///>

const std::string	Form::get_name() const
{
	return (name);
}

int 	Form::get_sign_grade() const
{
	return (sign_grade);
}

int		Form::get_exec_grade() const
{
	return (exec_grade);
}

bool		Form::get_is_signed() const
{
	return (is_signed);
}

///>

std::ostream		&operator	<< ( std::ostream &c, const Form &F )
{
	c << "Form: "<< F.get_name() << ", with [" << F.get_sign_grade() 
		<< "] as the minimal grade required to be signed"
		<< " and [" << F.get_exec_grade() << "] to be executed, is"
		<< (F.get_is_signed() ? " " : " not ") << "signed\n";
	return (c);
}
