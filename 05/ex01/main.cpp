#include "Form.hpp"
#include "Bureaucrat.hpp"

int		main()
{
	try {
		Form		form_one("form_one", 10, 1);
		Bureaucrat	b_one("b_one", 1);

		form_one.beSigned(b_one);
		std::cout << form_one;
		//
		Bureaucrat	b_two("b_two", 11);
		form_one.beSigned(b_two);
		std::cout << form_one;
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what();
	}

	//
	Bureaucrat	b("b_one", 10);
	Form		f("f_one", 1, 1);

	b.signForm(f);
}
