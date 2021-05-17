#include "Bureaucrat.hpp"

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
		fast = new ShrubberyCreationForm("Fast");
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

	bob->execForm(*fast);

	while (bob->getGrade() > fast->getGradeToExec())
	{
		bob->incGrade();
	}

	bob->execForm(*fast);
	
	std::cout << "-------------------------------------" << std::endl;
	RobotomyRequestForm *robot = new RobotomyRequestForm("Robert");


	while (bob->getGrade() > robot->getGradeToExec())
	{
		bob->incGrade();
	}
	bob->signForm(*robot);
	bob->execForm(*robot);

	std::cout << *robot;

	/*

	//copy test

	Form *cpy = new RobotomyRequestForm(*robot);

	std::cout << *cpy;

	delete cpy;

	*/

	delete robot;

	std::cout << "-------------------------------------" << std::endl;
	
	Form *ptr = new PresidentialPardonForm("Robert");


	while (bob->getGrade() > ptr->getGradeToExec())
	{
		bob->incGrade();
	}
	bob->signForm(*ptr);
	bob->execForm(*ptr);

	std::cout << *ptr;;

	delete ptr;
	delete bob;
	delete fast;

	return 0;
}