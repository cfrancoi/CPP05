#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() 
{
	
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
	if (grade <= 0)
	{
		throw(Bureaucrat::GradeTooHightExecption());
	}
	else if (grade > 150)
	{
		throw(Bureaucrat::GradeTooLowtExecption());
	}
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_grade = rhs.getGrade();
	return *this;
}


std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::signForm(Form &form) 
{
	try 
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::execForm(Form &form) 
{
	try 
	{
		form.execForm(*this);
		std::cout << _name << " exec " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << _name << " cannot exec " << form.getName() << " because " << e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

void Bureaucrat::incGrade(void) 
{
	if (_grade - 1 <= 0)
	{
		throw(Bureaucrat::GradeTooHightExecption());
	}
	else if (_grade - 1 > 150)
	{
		throw(Bureaucrat::GradeTooLowtExecption());
	}
	else
		_grade--;
}

void Bureaucrat::decGrade(void) 
{
	if (_grade + 1 <= 0)
	{
		throw(Bureaucrat::GradeTooHightExecption());
	}
	else if (_grade + 1 > 150)
	{
		throw(Bureaucrat::GradeTooLowtExecption());
	}
	else
		_grade--;
}



/* ************************************************************************** */