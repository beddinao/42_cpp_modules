#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &Ro )
{
	*this = Ro;
}

RobotomyRequestForm		&RobotomyRequestForm::operator = ( const RobotomyRequestForm &Ro )
{
	target = Ro.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::execute( Bureaucrat const &B ) const
{
	try {
		if (!get_is_signed())
			throw false;
		if (B.getGrade() > get_exec_grade())
		{
			std::cout << "the robotomy failed\n";
			throw AForm::GradeTooLowException();
		}
		std::cout << target << " has been robotomized "
			<< "successfully 50\% of the time\n";
	}
	catch ( bool i )
	{
		std::cout << get_name() << "Form is not yet signed\n";
	}
}
