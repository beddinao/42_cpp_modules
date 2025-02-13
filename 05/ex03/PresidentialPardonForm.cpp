#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &Pr )
{
	*this = Pr;
}

PresidentialPardonForm	&PresidentialPardonForm::operator = ( const PresidentialPardonForm &Pr )
{
	target = Pr.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::execute( Bureaucrat const &B ) const
{
	try {
		if (!get_is_signed())
			throw false;
		if (B.getGrade() > get_exec_grade())
		{
			std::cout << "the Presidential_Pardon just failed\n";
			throw AForm::GradeTooLowException();
		}
		std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
	}
	catch ( bool i )
	{
		std::cout << get_name() << " is not yet signed\n";
	}
}
