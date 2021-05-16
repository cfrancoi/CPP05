#include "Bureaucrat.hpp"

#include "Form.hpp"

#include <string>
#include <iostream>

int main(void)
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

	Form *fast;
	try 
	{
		fast = new Form("Fast", 68, 52);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		delete bob;
		return 1;
	}
	
	bob->signForm(*fast);
	
	std::cout << *bob;
	std::cout << *fast;

	while (bob->getGrade() > fast->getGradeToSign())
	{
		bob->incGrade();
	}


	bob->signForm(*fast);

	std::cout << *bob;
	std::cout << *fast;

	delete bob;
	delete fast;

	return 0;
}