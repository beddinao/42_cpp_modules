#include "Intern.hpp"

Intern::Intern() 
{
	forms_strs[0] = "shrubbery creation";
	forms_strs[1] = "robotomy request";
	forms_strs[2] = "presidential pardon";
}

Intern::~Intern() {}

Intern::Intern( const Intern &i )
{
	*this = i;
}

Intern	&Intern::operator = ( const Intern &i )
{
	return (*this);
}

AForm	*Intern::makeForm( std::string form_name, std::string target )
{
	AForm		*form = NULL;
	AForm		*forms_classes[3] = {
				new ShrubberyCreationForm(target),
				new RobotomyRequestForm(target),
				new PresidentialPardonForm(target)};

	for (int i = 0; i < 3 ; i++)
	{
		if (form_name == this->forms_strs[i])
			form = forms_classes[i],
			std::cout << "Intern creates \'"
				<< form_name << "\'" << std::endl;
		else
			delete forms_classes[i];
	}
	if (!form)
		std::cout << "no form found with the name \'" 
			<< form_name << "\'\n";
	return (form);
}
