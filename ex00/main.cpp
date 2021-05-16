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
		std::cerr << e.what() << std::endl;
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
	return 0;
}