#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string const & name) : Form("Robot request", 72, 45, name)
{
	srand(time(NULL));
}


RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form(src.getName(), src.getGradeToSign(), src.getGradeToExec(), src.getTarget())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	setSigned(rhs.getSigned());
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "Form " << i.getName() << " need grade : " << std::endl;
	o << " - to sign : " << i.getGradeToSign() << std::endl;
	o << " - to exec : " << i.getGradeToExec() << std::endl;
	o << "Status is :";
	if (i.getSigned())
	{
		o << " signed" << std::endl;
	}
	else
	{
		o << " not signed" << std::endl;
	}
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execForm(Bureaucrat &ref) const
{
	if (getSigned() == false)
	{
		throw(Form::FormNotSigned());
	}
	if (getGradeToExec() < ref.getGrade())
	{
		throw(Form::GradeTooLowtExecption());
	}
	

	int i;
	i = rand() % 2;
	if (i)
	{
		std::cout <<"* Brrzzz *" << std::endl;
		std::cout << getTarget() << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout <<"It's a failure." << std::endl;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */