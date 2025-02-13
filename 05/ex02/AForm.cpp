#include "AForm.hpp"

AForm::AForm()
	: is_signed(false), sign_grade(150), exec_grade(150) {}
AForm::~AForm() {}

void	AForm::execute( Bureaucrat const &a ) const {}

AForm::AForm ( std::string name, int new_sign_grade, int new_exec_grade)
	: name(name), is_signed(false), sign_grade(150), exec_grade(150)
{
	try {
		if (new_sign_grade < 1)
			throw AForm::GradeTooHighException();
		else if (new_sign_grade > 150)
			throw AForm::GradeTooLowException();
		int *s_ptr = (int*)(&sign_grade);
		*s_ptr = new_sign_grade;
	}
	catch (int a) {}
	try {
		if (new_exec_grade < 1)
			throw AForm::GradeTooHighException();
		else if (new_exec_grade > 150)
			throw AForm::GradeTooLowException();
		int *s_ptr = (int*)(&exec_grade);
		*s_ptr = new_exec_grade;
	}
	catch (int a) {}
}

AForm::AForm ( const AForm &_copy )
	: sign_grade(_copy.get_sign_grade()), exec_grade(_copy.get_exec_grade())
{
	*this = _copy;
}

AForm	&AForm::operator = ( const AForm &_copy )
{
	int	*sign_ptr = (int*)(&sign_grade);
	int	*exec_ptr = (int*)(&exec_grade);
	*sign_ptr = _copy.get_sign_grade();
	*exec_ptr = _copy.get_exec_grade();
	is_signed = _copy.is_signed;
	return (*this);
}

const	char*	AForm::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too High\n";
}

const	char*	AForm::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too Low\n";
}

void		AForm::beSigned( const Bureaucrat &B )
{
	try {
		if (B.getGrade() > sign_grade)
			throw AForm::GradeTooLowException();
		else if (B.getGrade() < 1)
			throw AForm::GradeTooHighException();
		is_signed = true;
	}
	catch (int a) {}
}

///>

const std::string	AForm::get_name() const
{
	return (name);
}

int 	AForm::get_sign_grade() const
{
	return (sign_grade);
}

int		AForm::get_exec_grade() const
{
	return (exec_grade);
}

bool		AForm::get_is_signed() const
{
	return (is_signed);
}


std::ostream		&operator	<< ( std::ostream &c, const AForm &F )
{
	c << "Form: "<< F.get_name() << ", with [" << F.get_sign_grade() 
		<< "] as the minimal grade required to be signed"
		<< " and [" << F.get_exec_grade() << "] to be executed, is"
		<< (F.get_is_signed() ? " " : " not ") << "signed\n";
	return (c);
}
