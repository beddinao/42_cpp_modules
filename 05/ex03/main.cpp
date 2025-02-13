#include "Intern.hpp"
#include <stdlib.h>

void	leaks_( void )
{
	system("leaks form");
}

int		main()
{
	//atexit(leaks_);
	
	Intern			someIntern;
	AForm		*correct_form = someIntern.makeForm("some name", "bender");
	if (correct_form)
		delete correct_form;

	AForm		*false_form = someIntern.makeForm("robotomy request", "wait");
	if (false_form)
		delete false_form;
}
