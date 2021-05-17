#include "Bureaucrat.hpp"

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include "Intern.hpp"

#include <string>
#include <iostream>

int main(int ac, char **argv)
{
	Bureaucrat * bob = NULL;

	try
	{
		bob = new Bureaucrat("BoB", 150);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	Intern unname = Intern();

	Form *ptr;
	ptr = unname.makeForm("that", "bill");
	if (ptr == NULL && ac == 3)
		ptr = unname.makeForm(argv[1], argv[2]);
	
	if (ptr != NULL)
	{
		bob->signForm(*ptr);
		while (bob->getGrade() > ptr->getGradeToExec())
		{
			bob->incGrade();
		}
		bob->signForm(*ptr);
		bob->execForm(*ptr);
	}

	return 0;
}