#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

static Form* CreatePresidential(std::string const & target) 
{
	return (new PresidentialPardonForm(target));
}

static Form* CreateRobotomy(std::string const & target) 
{
	return (new RobotomyRequestForm(target));
}

static Form* CreateShrubbery(std::string const & target) 
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern()
{
	_lst[0].fct = CreateShrubbery;		_lst[0].name = "shrubbery creation";
	_lst[1].fct = CreateRobotomy;		_lst[1].name = "robotomy request";
	_lst[2].fct = CreatePresidential;	_lst[2].name = "presidential pardon";
}

Intern::Intern( const Intern & src )
{
	*this = src;
	return ;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "I'm a intern without name";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/



Form * Intern::makeForm(std::string const & name, std::string const & target) 
{
	int	i;

	i = 0;

	while (i < 3)
	{
		if (name == _lst[i].name)
		{
			std::cout << "Intern create " << name << std::endl; 
			return (_lst[i].fct(target));
		}
		i++;
	}
	std::cerr <<  "Intern can't create " << name << std::endl;
	return NULL;
}




/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */