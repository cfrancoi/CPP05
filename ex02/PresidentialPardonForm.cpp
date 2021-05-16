#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & name) : Form("Presidential pardon", 25, 5, name)
{
	
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src) : Form(src.getName(), src.getGradeToSign(), src.getGradeToExec(), src.getTarget())
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}




/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	setSigned(rhs.getSigned());
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
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
	return o;;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execForm(Bureaucrat &ref) const
{
	if (getSigned() == false)
	{
		throw(Form::FormNotSigned());
	}
	if (getGradeToExec() < ref.getGrade())
	{
		throw(Form::GradeTooLowtExecption());
	}
	std::cout << getTarget() << " has been pardonned by Zafod Beeblobrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
