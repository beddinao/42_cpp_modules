#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &Sh )
{
	*this = Sh;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator = ( const ShrubberyCreationForm &Sh )
{
	target = Sh.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::execute( Bureaucrat const &B ) const
{
	std::fstream			file_out;
	std::string			line;
	try {
		if (!get_is_signed())
			throw false;
		if (B.getGrade() > get_exec_grade())
			throw AForm::GradeTooLowException();
		file_out.open(target + "_shrubbery", std::ios::out);
		line = "       /\\  /\\  /\\  ";
		file_out << line << line << line << line << std::endl;
 		line = "  /\\  /  \\/  \\/  \\ ";
		file_out << line << line << line << line << std::endl;
 		line = " /  \\/    \\/\\/    \\";
		file_out << line << line << line << line << std::endl;
 		line = "/    \\     \\ /    \\";
		file_out << line << line << line << line << std::endl;
 		line = "__  __\\     \\/    /";
		file_out << line << line << line << line << std::endl;
 		line = "  ||___  ____\\_  _\\";
		file_out << line << line << line << line << std::endl;
		line = "  ||   ||  ||  ||  ";
		file_out << line << line << line << line << std::endl;
		file_out.close();
	}
	catch ( bool i )
	{
		std::cout << get_name() << " is not yet signed\n";
	}
}
