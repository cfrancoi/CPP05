#include "Bureaucrat.hpp"

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
	

	try 
	{
		bob->decGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "dec Bob lvl 150 : "  << e.what() << std::endl;
	}

	try 
	{
		bob->incGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *bob;

	delete bob;

	try
	{
		bob = new Bureaucrat("BoB", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Create Bob lvl 0 : "<<  e.what() << std::endl;
	}
	try
	{
		bob = new Bureaucrat("BoB", 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *bob;
	try
	{
		bob->incGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "inc Bob lvl 1 : " << e.what() << std::endl;
	}
	
	return 0;
}